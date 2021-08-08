#ifndef CONFIG_H
#define CONFIG_H

//pins
#define WATCHY_SDA 21
#define WATCHY_SCL 22
#define WATCHY_ADC_PIN 33
#define WATCHY_RTC_PIN GPIO_NUM_27
#define WATCHY_CS 5
#define WATCHY_DC 10
#define WATCHY_RESET 9
#define WATCHY_BUSY 19
#define WATCHY_VIB_MOTOR_PIN 13
#define WATCHY_MENU_BTN_PIN 26
#define WATCHY_BACK_BTN_PIN 25
#define WATCHY_UP_BTN_PIN 32
#define WATCHY_DOWN_BTN_PIN 4
#define WATCHY_MENU_BTN_MASK GPIO_SEL_26
#define WATCHY_BACK_BTN_MASK GPIO_SEL_25
#define WATCHY_UP_BTN_MASK GPIO_SEL_32
#define WATCHY_DOWN_BTN_MASK GPIO_SEL_4
#define WATCHY_ACC_INT_MASK GPIO_SEL_14
#define WATCHY_BTN_PIN_MASK WATCHY_MENU_BTN_MASK|WATCHY_BACK_BTN_MASK|WATCHY_UP_BTN_MASK|WATCHY_DOWN_BTN_MASK
//display
#define DISPLAY_WIDTH 200
#define DISPLAY_HEIGHT 200
#define DARK_MODE true
//weather api
#define CITY_NAME "NEW+YORK" //if your city name has a space, replace with '+'
#define COUNTRY_CODE "US"
#define OPENWEATHERMAP_APIKEY "f058fe1cad2afe8e2ddc5d063a64cecb" //use your own API key :)
#define OPENWEATHERMAP_URL "http://api.openweathermap.org/data/2.5/weather?q="
#define TEMP_UNIT "metric" //use "imperial" for Fahrenheit"
#define WEATHER_UPDATE_INTERVAL 30 //minutes
//wifi
#define WIFI_AP_TIMEOUT 60
#define WIFI_AP_SSID "Watchy AP"
//menu
#define WATCHFACE_STATE -1
#define MAIN_MENU_STATE 0
#define APP_STATE 1
#define FW_UPDATE_STATE 2
#define MENU_HEIGHT 30
#define MENU_LENGTH 6
//set time
#define SET_HOUR 0
#define SET_MINUTE 1
#define SET_YEAR 2
#define SET_MONTH 3
#define SET_DAY 4
#define YEAR_OFFSET 1970
//BLE OTA
#define BLE_DEVICE_NAME "Enermis Watchy"
#define WATCHFACE_NAME "Watchy 7 Segment"
#define SOFTWARE_VERSION_MAJOR 1
#define SOFTWARE_VERSION_MINOR 0
#define SOFTWARE_VERSION_PATCH 0
#define HARDWARE_VERSION_MAJOR 1
#define HARDWARE_VERSION_MINOR 0
//sleep
#define SLEEP_TIMEOUT_MS 1000 // 10 sec
#define LOOP_DELAY_MS 10

#endif
