#ifndef WATCHY_CONTEXT_H
#define WATCHY_CONTEXT_H

#include "TimeManager.h"
#include "watchface.h"
#include <GxEPD2_BW.h>

class Context{
public:
  TimeManager *time_manager;
  Watchface *watchface;
  GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> *display;
  SemaphoreHandle_t display_mutex;
};

#endif
