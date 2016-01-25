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

// -----------------------------------------------------------------------------

/** Converts the given value to temperature
 */
char ConvertVoltageToTemperature( unsigned char sensor_value )
{
  float voltage = sensor_value * (5.0 / 1023.0) * 10; // 0.1V
  return voltage;
}

// -----------------------------------------------------------------------------

/** Read an analog value from given analog input, convert it to an temperature value
 *  and return this value.
 */
unsigned char ReadTemperatur( unsigned char sensor_pin )
{
  return ConvertVoltageToTemperature( analogRead( sensor_pin ) );
}

// -----------------------------------------------------------------------------------------------
