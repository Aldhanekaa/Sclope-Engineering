
#include <Arduino.h>

#ifndef LCD_Icons
#include <characters/degree.hpp>
#endif

#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD

// // Wiring: SDA pin is connected to A4 and SCL pin to A5.
// // Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4); // Change to (0x27,16,2) for 16x2 LCD.my address is (0x3F)

/********************************************************************/
// DS18B20 Sensor Configuration
#include <OneWire.h> 
#include <DallasTemperature.h>
/********************************************************************/
// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS 2 
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire); 

/********************************************************************/ 

#include <RTClib.h>

// #ifndef _LED_DATA
//   #include <data/LED_DATA.h>
// #endif

// #ifndef _sensor_previous_data_union
//   #include <data/sensor_previous_data_union.h>
// #endif

#ifndef _sensor
  #include <data/sensor.hpp>
#endif

#ifndef _sensors
    #include <data/sensors.hpp>
#endif

#ifndef MQ137_SENSOR_
  #include <data/MQ137_sensor.hpp>
#endif


#ifndef RefillWaterFunc
    #include <utils/refillWater.hpp>
#endif


#ifndef WaterChangeFunc
    #include <utils/waterChange.hpp>
#endif

// #ifndef _triggers 
//   #include <utils/triggers.h>
// #endif

// #include <utils/turn_led.h>

// #ifndef _printLCD
// #include <utils/printLCD.hpp>
// #endif

float calibration_value = 21.34;
int phval = 0; 
unsigned long int avgphval; 
int buffer_arr[10],temp;