/*

  _____        _                       ______                _                           _               
 / ____|      | |                     |  ____|              (_)                         (_)              
| (___    ___ | |  ___   _ __    ___  | |__    _ __    __ _  _  _ __    ___   ___  _ __  _  _ __    __ _ 
 \___ \  / __|| | / _ \ | '_ \  / _ \ |  __|  | '_ \  / _` || || '_ \  / _ \ / _ \| '__|| || '_ \  / _` |
 ____) || (__ | || (_) || |_) ||  __/ | |____ | | | || (_| || || | | ||  __/|  __/| |   | || | | || (_| |
|_____/  \___||_| \___/ | .__/  \___| |______||_| |_| \__, ||_||_| |_| \___| \___||_|   |_||_| |_| \__, |
                        | |                            __/ |                                        __/ |
                        |_|                           |___/                                        |___/

  copyrights 2021 Sclope Engineering 
*/

#include <imports.hpp>

#define TDSensor_PIN 3
#define TemperatureSensor_PIN 4

/* Ultrasonic Sensor use 2 digital pins btw */
// #define UltrasonicSensor_PIN 6
// #define UltrasonicSensor_PIN 7

#define waterLevelSensorPin A0
#define MQ137_PIN A1
#define pHSensor_PIN A2

// A0 = Analog Pin, 400 (nilai int) . 30
// D0 = Digital Pin, (nilai bool, boolean)

void setup() {
  // put your setup code here, to run once:

	pinMode(2, OUTPUT);
	pinMode(TDSensor_PIN, INPUT);


	Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Waterlevel_Sensor.setDataInside() = analogRead(waterLevelSensorPin);
  TDS_Sensor.setDataInside() = analogRead(TDSensor_PIN);

  Serial.println(Waterlevel_Sensor.getDataInside());

  if (Waterlevel_Sensor.getDataInside() < 100) {
    // masok air
  }
  

}
