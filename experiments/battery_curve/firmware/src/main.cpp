
#include <Arduino.h>
#include "espos_wifi.h"
#include "espos_time.h"
#include "TimeManager.h"
#include "main.h"
#include <HTTPClient.h>
#include "esp_adc_cal.h"

#define WIFI_SSID "xxx"
#define WIFI_PASS "xxx"

EsposWiFi wifi = EsposWiFi();
EsposTime rtc_time = EsposTime();
TimeManager time_manager = TimeManager();

static const adc1_channel_t BATTERY_READ_PIN = ADC1_GPIO33_CHANNEL;
esp_adc_cal_characteristics_t *adc_chars = new esp_adc_cal_characteristics_t;

void log_data(int timestamp, double voltage, double voltage2) {
    HTTPClient http;
    String url = "https://roels.me/bat/index.php?id=log2&v=";
    url += voltage;
    url += "&v2=";
    url += voltage2;
    http.begin(url.c_str());
    http.GET();
    http.end();
}

void setup(){

    Serial.begin(115200);

    // Configure ADC
    {
        adc1_config_width(ADC_WIDTH_BIT_12);
        adc1_config_channel_atten(BATTERY_READ_PIN, ADC_ATTEN_DB_11);
        esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, adc_chars);
    }

    // Connect WiFi
    {
        int16_t n = wifi.scan();
        int wifi_retry = 1;
        if((n == 0 || !wifi.ssid_exists(WIFI_SSID)) && wifi_retry > 0) {
            wifi_retry -= 1;
            n = wifi.scan();
        }
        wifi.connect(WIFI_SSID, WIFI_PASS);
    }

    // Sync with time server
    {
        int ntp_result = rtc_time.getNTPTime();
        time_manager.setTime(ntp_result);
    }

    // log dummy data to mark the setup() in the log
    log_data(0, 0.0, 0.0);

}

// 10 samples are made in a 1second period, and averaged
// this is because the voltage fluctuates a bit
double getBatteryVoltage2(){
    double result = 0.0;
    int analog;
    for(int i = 0; i < 10; i++) {
        delay(100);
        analog = adc1_get_raw(BATTERY_READ_PIN);
        result += esp_adc_cal_raw_to_voltage(analog, adc_chars) * 2.0 / 1000.0;
    }
    return result / 10.0;
}

// 10 samples are made in a 1second period, and averaged
// this is because the voltage fluctuates a bit
double getBatteryVoltage(){
    double result = 0.0;
    for(int i = 0; i < 10; i++) {
        delay(100);
        result += analogRead(WATCHY_ADC_PIN) / 4096.0 * 7.23;
    }
    return result / 10.0;
}

void loop(){
    log_data(0, getBatteryVoltage(), getBatteryVoltage2());
    delay(8000); // 8 sec because we already spent 2 seconds sampling
}

