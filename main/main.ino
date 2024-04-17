#include <Arduino.h>
#include "WaterPump.h"
#include "Scheduler.h"

/*
 * Constants
 */
const int PUMP_PIN = 12;                       // Pin to which the pump is connected
const int PUMP_LED_PIN = 13;                   // Pin to which the pump LED is connected
const unsigned long PUMP_ON_DURATION = 5000;  // Duration for which the pump should be on
const unsigned long PUMP_OFF_INTERVAL = 10000; // Interval between pump on/off cycles

/*
 * Global objects
 */
WaterPump waterPump(PUMP_PIN);                                    // Create a WaterPump object
Scheduler scheduler(waterPump, PUMP_ON_DURATION, PUMP_OFF_INTERVAL); // Create a Scheduler object

/*
 * Setup function
 */
void setup()
{

  // Initialize the pump and pump LED pins
  pinMode(PUMP_LED_PIN, OUTPUT);

  /*
   * Blink the pump LED 5 times to indicate that the system is ready
   */
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(PUMP_LED_PIN, HIGH);
    delay(500);
    digitalWrite(PUMP_LED_PIN, LOW);
    delay(500);
  }
}

/*
 * Loop function
 */
void loop()
{
  /*
   * Run the scheduler to control the pump
   */
  scheduler.run();

  /*
   * Update the pump LED based on the pump state
   */
  if (waterPump.isRunning())
  {
    digitalWrite(PUMP_LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(PUMP_LED_PIN, LOW);
  }
  delay(1000);
}
