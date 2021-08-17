
#include "espos_time.h"
#include <ESP32Time.h>

long EsposTime::getESP32Time() {
    return this->_esp32_time.getEpoch();
}

String EsposTime::getESP32TimeString() {
    return this->_esp32_time.getTime();
}

void EsposTime::setESP32Time(long epoch) {
    this->_esp32_time.setTime(epoch);
}

long EsposTime::getRTCTime() {

}

void EsposTime::setRTCTime(long epoch){

}

long EsposTime::getNTPTime() {

    configTime(0, 0, "pool.ntp.org");
    //configTzTime(TZ_Europe_Brussels, "pool.ntp.org");

    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)){
        return 0;
    }

    return mktime(&timeinfo);
}