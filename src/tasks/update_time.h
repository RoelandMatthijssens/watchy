#ifndef WATCHY_TASK_UPDATE_TIME_H
#define WATCHY_TASK_UPDATE_TIME_H

#include <Arduino.h>
#include "context.h"

void render_time(Context *context, String current_time){
  int16_t  x_off, y_off;
  uint16_t w, h;

  context->display->getTextBounds(current_time, 0, 0, &x_off, &y_off, &w, &h);
  int16_t x_pos = (DISPLAY_WIDTH-w) / 2;
  int16_t y_pos = (DISPLAY_HEIGHT-h) / 2;
  context->display->setPartialWindow(x_pos+x_off, y_pos+y_off, w, h);

  context->display->firstPage();
  do
  {
    context->display->fillScreen(BACKGROUND);
    context->display->setCursor(x_pos, y_pos);
    context->display->print(current_time);
  }
  while (context->display->nextPage());
}

void update_time( void *context_vp ){
  Context *context = (Context *) context_vp;
  while(1){
    if(xSemaphoreTake(context->display_mutex, 0) == pdTRUE){
      String current_time = context->time_manager->getTimeAsString("%H:%M:%S");
      render_time(context, current_time);
      xSemaphoreGive(context->display_mutex);
    }
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
  }
}



#endif
