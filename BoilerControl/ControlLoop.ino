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

#define OK           0 // successfull exection
#define ERR_UNDEF   -1 // Undefined error

// -----------------------------------------------------------------------------------------------
/** Control loop.

    @return  OK on success, on of ERR_* on error
*/
extern int controlLoop( SensorDataRingBuffer * sensorData )
{
  return OK;
}

// -----------------------------------------------------------------------------------------------
