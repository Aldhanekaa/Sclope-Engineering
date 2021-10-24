#ifndef _sensor
#include <data/sensor.hpp>
#endif

#define _sensors

Sensor<int, int> Waterlevel_Sensor("Water Level", 0);
Sensor<int,int> TDS_Sensor("TDS", 0);
Sensor<int,int> WaterTemperature_Sensor("Temperature", 0);

typedef struct lastUsedDataType  {
    int day;
    int hour;
    int minute;
    int second;
};

typedef struct pHSensorOtherDataStruct {
    boolean activated = false;
    struct lastUsedDataType lastUsed;
} pHSensorOtherData;


Sensor<float, pHSensorOtherData> pHLevel_Sensor("pH Level", 0);
