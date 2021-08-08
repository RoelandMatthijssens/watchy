#include <sys/time.h>
#include <Button2.h>
#include "config.h"

/* Button2 BTN_MENU(26); */
/* Button2 BTN_BACK(25); */
/* Button2 BTN_UP(32); */
/* Button2 BTN_DOWN(4); */

const int BTN_MENU = 26;
const int BTN_BACK = 25;
const int BTN_UP   = 32;
const int BTN_DOWN = 4;
struct timeval woke_up_at;

void setup(){
  Serial.begin(115200);
  log("starting setup");
  gettimeofday(&woke_up_at, NULL);
  log("woke up at");
}

void loop(){
  log("im in your loop");
  sleep_if_needed();
}

void debug() {
  log("debugging");
}

void sleep_if_needed() {
  if (time_to_sleep()) {
    deepSleep();
  } else {
    delay(LOOP_DELAY_MS);
  }
}

void deepSleep(){
  log("Going to sleep");
  esp_sleep_enable_ext1_wakeup(BTN_PIN_MASK, ESP_EXT1_WAKEUP_ANY_HIGH);
  esp_deep_sleep_start();
}

boolean time_to_sleep(){
  struct timeval current;
  gettimeofday(&current, NULL);
  int64_t current_ms = timeval_to_millis(current);
  int64_t woke_up_ms = timeval_to_millis(woke_up_at);
  log(current_ms - woke_up_ms);
  return current_ms - woke_up_ms > SLEEP_TIMEOUT_MS;
}

void log(String s){
  Serial.println(s);
}

int64_t timeval_to_millis(struct timeval t){
  return ((int64_t)t.tv_sec * 1000000L + (int64_t)t.tv_usec)/1000;
}
