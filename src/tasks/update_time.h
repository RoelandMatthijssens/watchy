#ifndef WATCHY_TASK_UPDATE_TIME_H
#define WATCHY_TASK_UPDATE_TIME_H

#include "context.h"

void update_time( void *context_vp ){
  Context *context = (Context *) context_vp;
  while(1){
    context->watchface->current_time = context->time_manager->getTimeAsString("%H:%M:%S");
    vTaskDelay( 100 / portTICK_PERIOD_MS );
  }
}

#endif
