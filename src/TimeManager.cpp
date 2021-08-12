#include "TimeManager.h"
#include <Arduino.h>
#include <DS3232RTC.h>

TimeManager::TimeManager(){
    this->parseCompileTime();
    this->RTC.squareWave(SQWAVE_NONE); //disable square wave output
    this->RTC.set(this->compile_time); //set RTC time to compile time
    //RTC.setAlarm(ALM2_EVERY_MINUTE, 0, 0, 0, 0); //alarm wakes up Watchy every minute
    //RTC.alarmInterrupt(ALARM_2, true); //enable alarm interrupt
}

void TimeManager::parseCompileTime(){
    const time_t FUDGE(10);
    const char *compDate = __DATE__, *compTime = __TIME__, *months = "JanFebMarAprMayJunJulAugSepOctNovDec";
    char compMon[3], *m;

    strncpy(compMon, compDate, 3);
    compMon[3] = '\0';
    m = strstr(months, compMon);

    tmElements_t tm;
    tm.Month = ((m - months) / 3 + 1);
    tm.Day = atoi(compDate + 4);
    tm.Year = atoi(compDate + 7) - 1970;
    tm.Hour = atoi(compTime);
    tm.Minute = atoi(compTime + 3);
    tm.Second = atoi(compTime + 6);

    time_t t = makeTime(tm);
    this->compile_time = t + FUDGE;
}

time_t TimeManager::getTime(){
    RTC.read(currentTime);
    return makeTime(currentTime);
}

String TimeManager::getTimeAsString(const char* format){
    time_t t = this->getTime();
    strftime(this->time_str_buff, 32, format, localtime(&t));
    return String(time_str_buff);
}
