#ifndef __BOILERDATA_H__
#define __BOILERDATA_H__
// -----------------------------------------------------------------------------------------------
using namespace std;

#include <string.h>
#include <LinkedList.h>

class SensorBank
{
  public:

    // -------------------------------------------
    // installed senors
    // -------------------------------------------
    char sensor_00;
    char sensor_01;
    char sensor_02;
    char sensor_03;
    char sensor_04;
    char sensor_05;
    char sensor_06;
    char sensor_07;
    char sensor_08;

    // -------------------------------------------
    // methods
    // -------------------------------------------
    void addItem( SensorBank * newItem );
    void dumpSensorData( void );

  private:
    LinkedList<SensorBank *> sensorHistory;
};

// -----------------------------------------------------------------------------------------------
#endif
