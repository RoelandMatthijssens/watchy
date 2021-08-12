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
  display.init(0, true);
  display.setFullWindow();
  display.display(false);
  display.setTextColor(FOREGROUND);
  while(1){
    int16_t  x_off, y_off;
    uint16_t w, h;
    String current_time = context->watchface->current_time;

    display.getTextBounds(current_time, 0, 0, &x_off, &y_off, &w, &h);
    int16_t x_pos = (DISPLAY_WIDTH-w) / 2;
    int16_t y_pos = (DISPLAY_HEIGHT-h) / 2;
    display.setPartialWindow(x_pos+x_off, y_pos+y_off, w, h);

    display.firstPage();
    do
    {
        display.fillScreen(BACKGROUND);
        display.setCursor(x_pos, y_pos);
        display.print(current_time);
    }
    while (display.nextPage());

    vTaskDelay( 500 / portTICK_PERIOD_MS );
  }
}

#endif
