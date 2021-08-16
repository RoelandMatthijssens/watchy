#ifndef WATCHY_TASK_UPDATE_BATTERY_H
#define WATCHY_TASK_UPDATE_BATTERY_H

#include <Arduino.h>
#include "config.h"
#include "context.h"

String get_battery_level(){
  return String(analogRead(WATCHY_ADC_PIN) / 4096.0 * 7.23);
}

void render_battery_level(Context *context, String battery_level){
  int16_t  x_off, y_off;
  uint16_t w, h;

  context->display->getTextBounds(battery_level, 0, 0, &x_off, &y_off, &w, &h);
  int16_t x_pos = 50-w;
  int16_t y_pos = 50-h;
  context->display->setPartialWindow(x_pos+x_off, y_pos+y_off, w, h);

  context->display->firstPage();
  do {
    context->display->fillScreen(BACKGROUND);
    context->display->setCursor(x_pos, y_pos);
    context->display->print(battery_level);
  }
  while (context->display->nextPage());
}

void update_battery( void *context_vp ){
  Context *context = (Context *) context_vp;
  while(1){
    if(xSemaphoreTake(context->display_mutex, 0) == pdTRUE){
      render_battery_level(context, get_battery_level());
      xSemaphoreGive(context->display_mutex);
    }
    vTaskDelay( 10000 / portTICK_PERIOD_MS );
  }
}

#endif
