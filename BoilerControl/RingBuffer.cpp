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

// -----------------------------------------------------------------------------
using namespace std;

#include "RingBuffer.h"

// -----------------------------------------------------------------------------

/** Returns the size of the ring buffer.
 */
unsigned int SensorDataRingBuffer::getBufferSize( void )
{
  return sizeof( sensor_history_ );
}

// -----------------------------------------------------------------------------

/** Returns the current ring buffer index.
 */
unsigned int SensorDataRingBuffer::getIndex( void )
{
  return current_index_;
}

// -----------------------------------------------------------------------------

/** Get the next valid ring buffer index.
 *
 *  @return   Returns a ring buffer index between 0 and sensor_data_buffer_maximum.
 */
unsigned int SensorDataRingBuffer::getNextIndexForIndex( unsigned int index )
{
  unsigned int  next_index = 0;

  if( index < ( sensor_data_buffer_maximum - 1 ) )
  {
    next_index = index + 1;
  }
  else
  {
    next_index = 0;
  }

  return next_index;
}

// -----------------------------------------------------------------------------

/** Get the next valid ring buffer index.
 *
 *  @return   Returns a ring buffer index between 0 and sensor_data_buffer_maximum.
 */
unsigned int SensorDataRingBuffer::getNextIndex( void )
{
  return getNextIndexForIndex( current_index_ );
}

// -----------------------------------------------------------------------------

/** Get the ring buffer index of the oldest entry.
 *
 *  @return   Returns a ring buffer index between 0 and sensor_data_buffer_maximum.
 */
unsigned int SensorDataRingBuffer::getStartIndex( void )
{
  int  start_index = current_index_ - item_count_;

  if( start_index < 0 )
  {
    start_index = sensor_data_buffer_maximum - start_index;
  }

  return start_index;
}

// -----------------------------------------------------------------------------

/** Add a new item of type SensorDataRingBuffer.
 */
unsigned int SensorDataRingBuffer::commitValueSet( void )
{
  unsigned int next_ring_buffer_index = getNextIndex();

  for( unsigned char sensor_id = 0; sensor_id < sensor_count; sensor_id++ )
  {
    this->sensor_history_[ next_ring_buffer_index ][ sensor_id ] = sensor_values_[ sensor_id ];
  }

  if( item_count_ < sensor_data_buffer_maximum ) item_count_++;
  current_index_ = next_ring_buffer_index;
}

// -----------------------------------------------------------------------------

/** Set a sensor value with id
 */
void SensorDataRingBuffer::setValueWithId( unsigned char sensor_id, unsigned char value )
{
  this->sensor_values_[ sensor_id ] = value;
}

// -----------------------------------------------------------------------------

/** Get a sensor value with id
 */
unsigned char SensorDataRingBuffer::getValueWithId( unsigned char sensor_id )
{
  return getSensorValueFromIndex( sensor_id, current_index_ );
}

// -----------------------------------------------------------------------------

/** Get a sensor value with id
 */
unsigned char SensorDataRingBuffer::getSensorValueFromIndex( unsigned char sensor_id, unsigned int index )
{
  return this->sensor_history_[ index ][ sensor_id ];
}

// -----------------------------------------------------------------------------

/** Returns a comma seperated string of current sensor values
 */
String SensorDataRingBuffer::getSensorValuesForIndexAsCSV( unsigned int index )
{
  String  csv_string = String();

  for( unsigned char sensor_id = 0; sensor_id < sensor_count; sensor_id++ )
  {
    csv_string += String( getSensorValueFromIndex( sensor_id, index ) );
    if( sensor_id < ( sensor_count - 1 ) ) csv_string += ",";
  }

  return csv_string;
}

// -----------------------------------------------------------------------------

/** Returns a comma seperated string of current sensor values
 */
String SensorDataRingBuffer::getSensorValuesAsCSV( void )
{
  return getSensorValuesForIndexAsCSV( current_index_ );
}

// -----------------------------------------------------------------------------

/** Dump the content of the sensor data ring buffer list to the serial line.
 */
void SensorDataRingBuffer::dumpRingBufferDataToSerial()
{
  int  index = getStartIndex();

  for( int loop_count = 0; loop_count < item_count_; loop_count++ )
  {
    Serial.print( getSensorValuesForIndexAsCSV( index ) );
    index = getNextIndexForIndex( index );
  }
}

// -----------------------------------------------------------------------------
