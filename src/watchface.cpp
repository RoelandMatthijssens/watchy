#include "watchface.h"

GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(GxEPD2_154_D67(WATCHY_CS, WATCHY_DC, WATCHY_RESET, WATCHY_BUSY));

const int FOREGROUND = DARK_MODE ? GxEPD_WHITE : GxEPD_BLACK;
const int BACKGROUND = DARK_MODE ? GxEPD_BLACK : GxEPD_WHITE;

void text_at(String s, int x, int y){
  display.setFont(&FreeMonoBold9pt7b);
  display.setCursor(x, y);
  display.setTextColor(FOREGROUND);
  display.println(s);
}

void refresh(){
  display.setFullWindow();
  display.init(0, true); //_initial_refresh to false to prevent full update on init
  display.fillScreen(BACKGROUND);
}

void full_update_watch_face(){
  refresh();
  text_at("Meep Meep", 0, 30);
  display.display(false);
}


void partial_update_watch_face(){
  Serial.println("doing partial watchface update");
}
