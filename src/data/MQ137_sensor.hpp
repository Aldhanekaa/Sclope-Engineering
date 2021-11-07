#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef _sensors
    #include <data/sensors.hpp>
#endif

#define MQ137_SENSOR_


const int RL = 47;  //The value of resistor RL is 47K
const int m = -0.263; //Enter calculated Slope 
const int b = 0.42; //Enter calculated intercept
const int Ro = 20; //Enter found Ro value
const int MQ_sensor = A0; //Sensor is connected to A4
Sensor<float,float> MQ137_SENSOR("Ammonia", 0);
