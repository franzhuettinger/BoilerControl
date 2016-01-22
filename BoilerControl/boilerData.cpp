#include "boilerData.h"
#include <Arduino.h>

/**
   Add a new item of type SensorBank.
*/
void SensorBank::addItem( SensorBank * newItem )
{
  this->sensorHistory.add( newItem );
}

/**
   Dump the content of the sensor data list to the serial line.
*/
void SensorBank::dumpSensorData()
{
  Serial.print(this->sensorHistory.size());

  SensorBank *data;

  for (int i = 0; i < sensorHistory.size(); i++)
  {
    data = this->sensorHistory.get(i);
    Serial.print(data->sensor_00);
  }
}

