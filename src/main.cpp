#include <Arduino.h>
#include <GxEPD2_BW.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "watchface.h"
#include "TimeManager.h"
#include "tasks/init_display.h"
#include "tasks/update_time.h"
#include "tasks/update_battery.h"
#include "context.h"

Context context;
void setup(){
  Serial.begin(115200);
  context.time_manager = new TimeManager();
  context.watchface = new Watchface();
  GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(GxEPD2_154_D67(WATCHY_CS, WATCHY_DC, WATCHY_RESET, WATCHY_BUSY));
  context.display = &display;

  xTaskCreate( init_display,   "init_display",   10000, &context, 2, NULL);
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  xTaskCreate( update_time,    "update_time",    2000,  &context, 1, NULL);
  xTaskCreate( update_battery, "update_battery", 10000, &context, 1, NULL);

  vTaskDelete(NULL);
}

void loop(){
}
