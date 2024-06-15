/*
    Project name : Temperature sensor module Waterproof DS18B20
    Modified Date: 15-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-temperature-sensor-module-waterproof-ds18b20
*/

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to digital pin 2
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  
  // Start up the library
  sensors.begin();
}

void loop() {
  // Call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  sensors.requestTemperatures(); 
  
  // Print the temperature in Celsius from DS18B20
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0)); // Index 0 refers to the first DS18B20 sensor
  Serial.println(" °C");

  delay(1000); // Wait for a second
}
