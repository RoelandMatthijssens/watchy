#ifndef WATCHY_INIT_DISPLAY_H
#define WATCHY_INIT_DISPLAY_H

#include "context.h"
#include "config.h"
#include <GxEPD2_BW.h>

const int FOREGROUND = GxEPD_WHITE;
const int BACKGROUND = GxEPD_BLACK;

void init_display( void *context_vp ){
  Context *context = (Context *) context_vp;
  context->display->init(0, true);
  context->display->setFullWindow();
  context->display->fillScreen(BACKGROUND);
  context->display->display(false);
  context->display->setTextColor(FOREGROUND);
  while(1){
    vTaskDelay( 1*60*60*1000 / portTICK_PERIOD_MS );
  }
}


#endif
