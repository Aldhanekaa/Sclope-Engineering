#ifndef _sensor
#include <data/sensor.hpp>
#endif


#ifndef _sensors
#define _sensors
#endif


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

const int TDSensor_PIN =  A3;
const int TemperatureSensor_PIN  = 4;
const int CLICKED = HIGH;

/* Relay Initialisation */
const int SupplyWaterRelay = 42;
const int waterPumpRelay = 40;
const int KettleRelay = 44;


/* end of Relay I#define PtKRelay 25
nitialisation */


/* Ultrasonic Sensor use 2 digital pins btw */
// #define UltrasonicSensor_PIN 6
// #define UltrasonicSensor_PIN 7

static const uint8_t waterLevelSensorPin = A0;
static const uint8_t MQ137_PIN = A1;
static const uint8_t pHSensor_PIN = A2;