#ifndef WATERPUMP_H
#define WATERPUMP_H

#include <Arduino.h>

class WaterPump {
private:
  const int pin;
  bool isOn;

public:
  WaterPump(int pin);
  void turnOn();
  void turnOff();
  bool isRunning();
};

#endif
