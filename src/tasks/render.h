#ifndef WATCHY_TASK_RENDER_H
#define WATCHY_TASK_RENDER_H

#include "context.h"
#include "config.h"
#include <GxEPD2_BW.h>

const int FOREGROUND = GxEPD_WHITE;
const int BACKGROUND = GxEPD_BLACK;
GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(GxEPD2_154_D67(WATCHY_CS, WATCHY_DC, WATCHY_RESET, WATCHY_BUSY));

void render( void *context_vp ){
  Context *context = (Context *) context_vp;
  display.init();
  display.setFullWindow();
  display.setTextColor(FOREGROUND);
  while(1){
    display.fillScreen(BACKGROUND);
    display.setCursor(50, 50);
    display.println(context->watchface->current_time);
    display.display(true);
    vTaskDelay( 60000 / portTICK_PERIOD_MS );
  }
}

#endif
