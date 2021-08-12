#ifndef WATCHY_CONTEXT_H
#define WATCHY_CONTEXT_H

#include "TimeManager.h"
#include "watchface.h"

class Context{
public:
  TimeManager *time_manager;
  Watchface *watchface;
};

#endif
