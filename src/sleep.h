#include <Arduino.h>
#include <sys/time.h>
#include "config.h"

void sleep_if_needed(struct timeval woke_up_at);
