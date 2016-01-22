#include <LinkedList.h>
#include "boilerData.h"

// ----------------------------------------------------------------------------
// Arduino pins
// ----------------------------------------------------------------------------
int sensorPin_00 = 0;

// ----------------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------------
SensorBank * sensorHistory;

// ----------------------------------------------------------------------------

/**
   Setup!
*/
void setup()
{
  // -------------------------------------------
  // create a new sensor data history
  // -------------------------------------------
  sensorHistory = new SensorBank();

  // -------------------------------------------
  // setup up our I/O's
  // -------------------------------------------

  // -------------------------------------------
  //  setup serial
  // -------------------------------------------
  Serial.begin(9600);
}


/**
   Main loop!
*/
void loop()
{
  SensorBank * newItem = new SensorBank();

  // -------------------------------------------
  // read values from all sensors and store it
  // in the history.
  // -------------------------------------------
  newItem->sensor_00 = SensorValueToTemperature( analogRead( sensorPin_00 ) );
  newItem->sensor_01 = SensorValueToTemperature( analogRead( sensorPin_00 ) );
  newItem->sensor_02 = SensorValueToTemperature( analogRead( sensorPin_00 ) );

  sensorHistory->addItem( newItem );

  // -------------------------------------------
  // call the control loop to do something with
  // the gathered sensor data.
  // -------------------------------------------
  controlLoop( newItem );

  sensorHistory->dumpSensorData();
  Serial.println(".");
}
