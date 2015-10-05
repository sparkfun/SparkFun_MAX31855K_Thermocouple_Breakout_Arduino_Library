/**************** MAX31855K_Thermocouple_Digitizer_Example.ino *****************
 *                                                                             *
 * MAX31855K Thermocouple Breakout Example Code                                *
 * brent@sparkfun.com                                                          *
 * March 26th 2015                                                             *
 * https://github.com/sparkfun/MAX31855K_Thermocouple_Digitizer                *
 *                                                                             *
 * Use the "serial monitor" window to read a temperature sensor.               *
 *                                                                             *
 * Circuit:                                                                    *
 * MAX31855K breakout attached to the following pins                           *
 *  SS:   pin 10                                                               *
 *  MOSI: pin 11 (NC)                                                          *
 *  MISO: pin 12                                                               *
 *  SCK:  pin 13                                                               *
 *  VCC:  pin 14                                                               *
 *  GND:  pin 15                                                               *
 *                                                                             *
 *                                                                             *
 * Development environment specifics:                                          *
 * 1.6.4                                                                       *
 * Arduino Pro Mini 328 3.3V/8MHz                                              *
 *                                                                             *
 * This code is beerware; if you see me (or any other SparkFun employee) at    *
 * the local, and you've found our code helpful, please buy us a round!        *
 * Distributed as-is; no warranty is given.                                    *
 ******************************************************************************/

#include <SparkFunMAX31855k.h> // Using the max31855k driver
#include <SPI.h>  // Included here too due Arduino IDE; Used in above header

// Define SPI Arduino pin numbers (Arduino Pro Mini)
const uint8_t CHIP_SELECT_PIN = 10; // Using standard CS line (SS)
// SCK & MISO are defined by Arduiino
const uint8_t VCC = 14; // Powering board straight from Arduino Pro Mini
const uint8_t GND = 15;

// Instantiate an instance of the SparkFunMAX31855k class.  There are 4
// parameters, but only the first is required. The parameters are (in order):
// chip select pin, VCC pin, 0V pin, debug flag (bool).
// Here are some examples. Only use 1 at a time unless you have more than one
// sensor.

// This version uses IOs for power and ground but doesn't print debug messages.
SparkFunMAX31855k probe(CHIP_SELECT_PIN, VCC, GND);

// This version relies on power and doesn't print debug messages
//SparkFunMAX31855k probe(CHIP_SELECT_PIN);

// This example doesn't use IO to power the IC, but has serial debug enabled
//SparkFunMAX31855k probe(CHIP_SELECT_PIN, NONE, NONE, true);

void setup() {
  Serial.begin(9600);
  Serial.println("\nBeginning...");
  delay(50);  // Let IC stabilize or first readings will be garbage
}

void loop() {
  float temperature;
  
  // Read methods return NAN if they don't have a valid value to return.
  // The following conditionals only print the value if it's not NAN.
  temperature = probe.readCJT();
  if (!isnan(temperature)) {
    Serial.print("Cold Junction Temperature is (˚C): ");
    Serial.println(temperature);
  }
  
  // Read the temperature in Celsius
  temperature = probe.readTempC();
  if (!isnan(temperature)) {
    Serial.print("Temp[C]=");
    Serial.println(temperature);
  }

  // Read the temperature in Fahrenheit
  temperature = probe.readTempF();
  if (!isnan(temperature)) {
    Serial.print("Temp[F]=");
    Serial.println(temperature);
  }

  // Read the temperature in Kelvin
  temperature = probe.readTempK();
  if (!isnan(temperature)) {
    Serial.print("Temp[K]=");
    Serial.println(temperature);
  }

  // Read the temperature in Rankine
  temperature = probe.readTempR();
  if (!isnan(temperature)) {
    Serial.print("Temp[R]=");
    Serial.println(temperature);
  }

  delay(750);
}
