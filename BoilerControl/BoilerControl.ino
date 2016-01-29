/** Boiler control - a boiler monitoring and control application
 *
 *  Copyright (C) 2016  Franz Huettinger, Tobias Baumann
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "RingBuffer.h"
#include "SensorConfig.h"

// -----------------------------------------------------------------------------
// Global variables
// -----------------------------------------------------------------------------
SensorDataRingBuffer * sensor_history;

// -----------------------------------------------------------------------------

/** Setup!
 */
void setup()
{
  sensor_history = new SensorDataRingBuffer();

  // -------------------------------------------
  // Setup up your I/O's here:
  // -------------------------------------------

  // -------------------------------------------
  Serial.begin( 9600 );
  while (!Serial) { /* wait for serial line */ }

  // -------------------------------------------
  // Print welcome message!
  // -------------------------------------------
  Serial.println( "Boiler contorl" );
  Serial.println( "Ring buffer size: " + String( sensor_history->getBufferSize() ) + " bytes" );
}

// -----------------------------------------------------------------------------

/** Main loop!
 */
void loop()
{
  static unsigned int  samples = 0;

  // ---------------------------------------------------------------------------
  // read analog values, convert them into a temperature value and store them
  // ---------------------------------------------------------------------------
  sensor_history->setValueWithId( sensor_00, ReadTemperatur( sensorPin_00 ) );
  //sensor_history->setValueWithId( sensor_01, ReadTemperatur( sensorPin_01 ) );
  //sensor_history->setValueWithId( sensor_02, ReadTemperatur( sensorPin_02 ) );
  //sensor_history->setValueWithId( sensor_03, ReadTemperatur( sensorPin_03 ) );
  //sensor_history->setValueWithId( sensor_04, ReadTemperatur( sensorPin_04 ) );
  //sensor_history->setValueWithId( sensor_05, ReadTemperatur( sensorPin_05 ) );
  //sensor_history->setValueWithId( sensor_06, ReadTemperatur( sensorPin_06 ) );
  //sensor_history->setValueWithId( sensor_07, ReadTemperatur( sensorPin_07 ) );
  //sensor_history->setValueWithId( sensor_08, ReadTemperatur( sensorPin_08 ) );
  //sensor_history->setValueWithId( sensor_09, ReadTemperatur( sensorPin_09 ) );

  sensor_history->commitValueSet();

  // ---------------------------------------------------------------------------
  // execute the boiler control loop - the actual control function
  // ---------------------------------------------------------------------------
  controlLoop( sensor_history );

  // ---------------------------------------------------------------------------
  Serial.println( String( samples++ ) + ", data: [" + sensor_history->getSensorValuesAsCSV() + "], Ring buffer index: " + String( sensor_history->getIndex() ) );
  delay( 2 * 1000 );
}

// -----------------------------------------------------------------------------
