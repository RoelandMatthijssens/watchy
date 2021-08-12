#ifndef WATCHY_WATCHFACE_H
#define WATCHY_WATCHFACE_H

#include <Arduino.h>

class Watchface{
public:
  String current_time;
  String battery_level;
  Watchface();
};

#endif
