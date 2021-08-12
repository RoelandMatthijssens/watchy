#ifndef WATCHY_TASK_RENDER_H
#define WATCHY_TASK_RENDER_H

#include "context.h"
#include "config.h"
#include <GxEPD2_BW.h>

const int FOREGROUND = GxEPD_WHITE;
const int BACKGROUND = GxEPD_BLACK;
GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(GxEPD2_154_D67(WATCHY_CS, WATCHY_DC, WATCHY_RESET, WATCHY_BUSY));

void render_time(String current_time){
    int16_t  x_off, y_off;
    uint16_t w, h;
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
}

void render_battery_level(String battery_level){
    int16_t  x_off, y_off;
    uint16_t w, h;
    display.getTextBounds(battery_level, 0, 0, &x_off, &y_off, &w, &h);
    int16_t x_pos = 50-w;
    int16_t y_pos = 50-h;
    display.setPartialWindow(x_pos+x_off, y_pos+y_off, w, h);

    display.firstPage();
    do {
        display.fillScreen(BACKGROUND);
        display.setCursor(x_pos, y_pos);
        display.print(battery_level);
    }
    while (display.nextPage());
}

void render( void *context_vp ){
  Context *context = (Context *) context_vp;
  display.init(0, true);
  display.setFullWindow();
  display.display(false);
  display.setTextColor(FOREGROUND);
  while(1){
    String current_time = context->watchface->current_time;
    String battery_level = context->watchface->battery_level;
    render_time(current_time);
    render_battery_level(battery_level);

    vTaskDelay( 500 / portTICK_PERIOD_MS );
  }
}


#endif
