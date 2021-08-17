#ifndef espos_core_wifi_h
#define espos_wifi_h

#include "WiFi.h"

class EsposWiFi {

private:
    int16_t _scan_results_count;

public:
    void on();
    void off();
    bool connect(String ssid, String pass);
    void disconnect();
    int16_t scan();
    bool ssid_exists(String ssid);

};

#endif