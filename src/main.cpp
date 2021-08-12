#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "watchface.h"
#include "TimeManager.h"
#include "tasks/render.h"
#include "tasks/update_time.h"
#include "context.h"

void setup(){
  Serial.begin(115200);
  Context context;
  context.time_manager = new TimeManager();
  context.watchface = new Watchface();

  xTaskCreate( render,      "render",      10000, &context, 1, NULL);
  xTaskCreate( update_time, "update_time", 10000, &context, 1, NULL);

  vTaskDelete(NULL);
}

void loop(){
}
