#include <sys/time.h>
#include <Button2.h>
#include "config.h"
#include "sleep.h"

struct timeval woke_up_at;

void setup(){
  Serial.begin(115200);
  Serial.println("starting setup");
  gettimeofday(&woke_up_at, NULL);
  Serial.println("woke up at");
}

void loop(){
  Serial.println("im in your loop");
  sleep_if_needed(woke_up_at);
}

void debug() {
  Serial.println("debugging");
}
