#ifndef WATCHY_TASK_UPDATE_BATTERY_H
#define WATCHY_TASK_UPDATE_BATTERY_H

#include <Arduino.h>
#include "config.h"
#include "context.h"

void update_battery( void *context_vp ){
  Context *context = (Context *) context_vp;
  while(1){
    context->watchface->battery_level = String(analogRead(WATCHY_ADC_PIN) / 4096.0 * 7.23);
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
  }
}

#endif
