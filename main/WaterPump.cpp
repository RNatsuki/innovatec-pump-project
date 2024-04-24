#include "WaterPump.h"

WaterPump::WaterPump(int pin) : pin(pin), isOn(false) {
  pinMode(pin, OUTPUT);
}

void WaterPump::turnOn() {
  digitalWrite(pin, LOW);
  isOn = true;
}

void WaterPump::turnOff() {
  digitalWrite(pin, HIGH);
  isOn = false;
}

bool WaterPump::isRunning() {
  return isOn;
}
