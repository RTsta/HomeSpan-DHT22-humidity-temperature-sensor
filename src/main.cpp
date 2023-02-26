#include <Arduino.h>
#include "HomeSpan.h"
#include "DEV_Sensors.h"

void setup() {
  Serial.begin(9600);
  homeSpan.begin(Category::Sensors,"HomeSpan DHT22 hum/temp sensor");

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify(); 
      new Characteristic::Name("Temp Sensor");
    new DEV_TempSensor();  

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify(); 
      new Characteristic::Name("Humidity Sensor");
    new DEV_HumSensor();  

  
}

void loop() {
  homeSpan.poll(); 
}
