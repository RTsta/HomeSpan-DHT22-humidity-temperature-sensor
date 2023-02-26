#include <Arduino.h>
#include "HomeSpan.h"
#include <DHT.h>

//Constants
#define DHTPIN 25
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

int updateTime = 30000;

struct DEV_TempSensor : Service::TemperatureSensor {
  SpanCharacteristic *temp;
  DEV_TempSensor() : Service::TemperatureSensor(){       // constructor() method
    temp=new Characteristic::CurrentTemperature(20.0);
    temp->setRange(-40,80);

    dht.begin();
  } // end constructor

  void loop(){
    if(temp->timeVal() > updateTime){
      float temperature = dht.readTemperature();
      temp->setVal(temperature);          
    }
  } // loop
};

struct DEV_HumSensor : Service::HumiditySensor {
  SpanCharacteristic *hum;
  DEV_HumSensor() : Service::HumiditySensor(){       // constructor() method
    hum=new Characteristic::CurrentRelativeHumidity(50.0);
    hum->setRange(0,100);

    dht.begin();
  } // end constructor

  void loop(){
    if(hum->timeVal() > updateTime){
      float humidity = dht.readHumidity();
      hum->setVal(humidity);          
    }
  } // loop
};