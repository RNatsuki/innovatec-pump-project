#include "Scheduler.h"

Scheduler::Scheduler(WaterPump& pump, unsigned long pumpOnDuration, unsigned long pumpOffInterval)
    : pump(pump), pumpOnDuration(pumpOnDuration), pumpOffInterval(pumpOffInterval), lastRunTime(0), pumpState(false) {}

void Scheduler::run() {
  unsigned long currentTime = millis();
  if (pumpState) {
    if (currentTime - lastRunTime >= pumpOnDuration) {
      pump.turnOff();
      pumpState = false;
      lastRunTime = currentTime;
    }
  } else {
    if (currentTime - lastRunTime >= pumpOffInterval) {
      pump.turnOn();
      pumpState = true;
      lastRunTime = currentTime;
    }
  }
}
