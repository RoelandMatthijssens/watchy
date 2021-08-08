#include <sys/time.h>
#include <Button2.h>
#include "config.h"
#include "sleep.h"
#include "watchface.h"

struct timeval woke_up_at;

void setup(){
  Serial.begin(115200);
  Serial.println("starting setup");
  gettimeofday(&woke_up_at, NULL);
  Serial.println("woke up at");
  full_update_watch_face();
}

void loop(){
  Serial.println("im in your loop");
  partial_update_watch_face();
  sleep_if_needed(woke_up_at);
}

void debug() {
  Serial.println("debugging");
}
