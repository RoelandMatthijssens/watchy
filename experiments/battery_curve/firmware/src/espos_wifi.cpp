
#include "espos_wifi.h"

void EsposWiFi::on() {
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
}

void EsposWiFi::off() {
    WiFi.mode(WIFI_OFF);
}

bool EsposWiFi::connect(String ssid, String pass) {

    int timeout = 30000;
    WiFi.begin(ssid.c_str(), pass.c_str());

    wl_status_t wifi_status = WiFi.status();
    while(wifi_status != WL_CONNECTED && timeout > 0) {
        int wait_time = 500; // check status every 500ms
        wifi_status = WiFi.status();
        timeout -= wait_time;
        delay(wait_time);
    }

    if(wifi_status == WL_CONNECTED) {
        return true;
    } else {
        return false;
    }

}

void EsposWiFi::disconnect() {
    WiFi.disconnect();
}

int16_t EsposWiFi::scan() {
    this->_scan_results_count = WiFi.scanNetworks();
    return this->_scan_results_count;
}

// call scan before using this!
bool EsposWiFi::ssid_exists(String ssid) {
    for(int i = 0; i < this->_scan_results_count; i++) {
        if(WiFi.SSID(i) == ssid) {
            return true;
        }
    }
    return false;
}



