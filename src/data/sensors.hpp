


#ifndef _sensors
    #include <data/sensors.hpp>
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

const int TDSensor_PIN =  3;
const int TemperatureSensor_PIN  = 4;
const int CLICKED = HIGH;

/* Relay Initialisation */
const int waterPumpRelay = 22;
const int SupplyWaterRelay = 23;
const int KettleRelay = 23;
const int PtKRelay = 24;
const int PtRRelay = 25;

/* end of Relay I#define PtKRelay 25
nitialisation */


/* Ultrasonic Sensor use 2 digital pins btw */
// #define UltrasonicSensor_PIN 6
// #define UltrasonicSensor_PIN 7

static const uint8_t waterLevelSensorPin = A0;
static const uint8_t MQ137_PIN = A1;
static const uint8_t pHSensor_PIN = A2;