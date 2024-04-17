#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "WaterPump.h"

class Scheduler {
private:
  WaterPump& pump;
  unsigned long lastRunTime;
  unsigned long pumpOnDuration;
  unsigned long pumpOffInterval;
  bool pumpState;

public:
  Scheduler(WaterPump& pump, unsigned long pumpOnDuration, unsigned long pumpOffInterval);
  void run();
};

#endif
