
#ifndef espos_time_H
#define espos_time_H

#define TZ_Europe_Brussels	PSTR("CET-1CEST,M3.5.0,M10.5.0/3")
#include <ESP32Time.h>

class EsposTime {

private:
    ESP32Time _esp32_time = ESP32Time();

public:
    long getNTPTime();
    long getESP32Time();
    String getESP32TimeString();
    void setESP32Time(long epoch);
    long getRTCTime();
    void setRTCTime(long epoch);

};

#endif
