/** SensorDataRingBuffer - a data store for gathered sensor values
 *
 *  Copyright (C) 2016  Franz Huettinger
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

#ifndef __RINGBUFFER_H__
#define __RINGBUFFER_H__
// -----------------------------------------------------------------------------
using namespace  std;

#include <Arduino.h>
#include <string.h>

#include "SensorConfig.h"

// -----------------------------------------------------------------------------

/** Sensor data ring buffer
 */
class  SensorDataRingBuffer
{
public:
  void           setValueWithId( unsigned char sensor_id, unsigned char value );
  unsigned char  getValueWithId( unsigned char sensor_id );
  unsigned char  getSensorValueFromIndex( unsigned char sensor_id, unsigned int index );
  unsigned int   commitValueSet( void );

  String         getSensorValuesAsCSV( void );
  String         getSensorValuesForIndexAsCSV( unsigned int index );

  void           dumpRingBufferDataToSerial( void );

  unsigned int   getStartIndex( void );
  unsigned int   getNextIndex( void );
  unsigned int   getIndex( void );
  unsigned int   getNextIndexForIndex( unsigned int index );

  unsigned int   getBufferSize( void );

private:
  int   item_count_;
  int   current_index_;
  char  sensor_values_[ sensor_count ];
  char  sensor_history_[ sensor_data_buffer_maximum ][ sensor_count ];
};

// -----------------------------------------------------------------------------
#endif
