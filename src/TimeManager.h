#ifndef WATCHY_TIMEMANAGER_H
#define WATCHY_TIMEMANAGER_H

#include <TimeLib.h>
#include <Arduino.h>
#include <DS3232RTC.h>

class TimeManager {

private:
    time_t compile_time;
    tmElements_t currentTime;
    char time_str_buff[32];
    DS3232RTC RTC;

private:
    void parseCompileTime();

public:
    TimeManager();
    time_t getTime();
    String getTimeAsString(const char* format);

};

#endif
