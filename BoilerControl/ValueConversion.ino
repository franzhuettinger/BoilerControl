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
char ConvertVoltageToTemperature( unsigned int sensor_value )
{
  //TODO: this has to be improved!
  
  float U = 5.0;
  float Rf = 115;
  float R0 = 100;
  float Ut = sensor_value * (U / 1023.0);
  float Uf = U - Ut;
  float Rt = Rf * Ut / Uf;

  // adjustment  
  float c = 0.0;
  if( Rt <= 110.0 ) c = 10.0 / (103.90-100.0);
  else if( Rt > 110.0 && Rt <= 145.69) c = 40.0 / (115.54-100.0);
  else if( Rt > 145.69) c = 200.0 / (175.84-100.0);

  // temperature
  float T = (Rt - R0) * c;
  
  Serial.println( "Ut = " + String( Ut ) + "V, sensor_value = " + String( sensor_value ) + ", Rt = " + String(Rt) + " Ohm, T = "+ String(T) + " C"); 
  
  return T;
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
