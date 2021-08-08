#include "sleep.h"

int64_t timeval_to_millis(struct timeval t){
  return ((int64_t)t.tv_sec * 1000000L + (int64_t)t.tv_usec)/1000;
}

bool time_to_sleep(struct timeval woke_up_at){
  struct timeval current;
  gettimeofday(&current, NULL);
  int64_t current_ms = timeval_to_millis(current);
  int64_t woke_up_ms = timeval_to_millis(woke_up_at);
  return current_ms - woke_up_ms > SLEEP_TIMEOUT_MS;
}

void deepSleep(){
  Serial.println("Going to sleep");
  esp_sleep_enable_ext1_wakeup(WATCHY_BTN_PIN_MASK, ESP_EXT1_WAKEUP_ANY_HIGH);
  esp_deep_sleep_start();
}

void sleep_if_needed(struct timeval woke_up_at) {
  if (time_to_sleep(woke_up_at)) {
    deepSleep();
  } else {
    delay(LOOP_DELAY_MS);
  }
}
