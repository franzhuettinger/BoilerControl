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

#ifndef __SENSORSCONFIG_H__
#define __SENSORSCONFIG_H__

// -----------------------------------------------------------------------------------------------
const unsigned int  sensor_data_buffer_maximum = 180;

// -----------------------------------------------------------------------------------------------

/** Analog pin assignement.
 *
 *  exp.: sensor_pin_{FUNCTION} = {ARDUINO_PIN_ID}
 */
typedef enum analog_pins
{
  sensorPin_00 = A0,
  sensorPin_01 = A1,
  sensorPin_02 = A2,
  sensorPin_03 = A3,
  sensorPin_04 = A0,
  sensorPin_05 = A1,
  sensorPin_06 = A2,
  sensorPin_07 = A3,
  sensorPin_08 = A0,
  sensorPin_09 = A1
} analog_pins;

// -----------------------------------------------------------------------------------------------

/** Sensor id's for all active sensors.
 */
typedef enum ananlog_sensors
{
  sensor_00 = 0,
  sensor_01,
  sensor_02,
  sensor_03,
  sensor_04,
  sensor_05,
  sensor_06,
  sensor_07,
  sensor_08,
  sensor_09,
  sensor_count
} analog_sensors;

// -----------------------------------------------------------------------------------------------
#endif
