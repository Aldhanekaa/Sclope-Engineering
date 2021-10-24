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
#define CLICKED HIGH

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
  pinMode(TDSensor_PIN, INPUT);
  pinMode(23, INPUT);

  sensors.begin(); 


	Serial.begin(9600);
}

void loop() {

  int measurepHButton = digitalRead(23);

  // put your main code here, to run repeatedly:
  Waterlevel_Sensor.setData() = analogRead(waterLevelSensorPin);
  TDS_Sensor.setData() = analogRead(TDSensor_PIN);

  sensors.requestTemperatures();
  WaterTemperature_Sensor.setData() = sensors.getTempCByIndex(0);

  Serial.println(Waterlevel_Sensor.getData());

  /**************************************************************** Main Program ****************************************************************/
  if (measurepHButton == CLICKED) {
    for(int i=0;i<10;i++) { 
      buffer_arr[i]=analogRead(A0);
      delay(30);
    }
    for(int i=0;i<9;i++) {
      for(int j=i+1;j<10;j++) {
        if(buffer_arr[i]>buffer_arr[j]) {
          temp=buffer_arr[i];
          buffer_arr[i]=buffer_arr[j];
          buffer_arr[j]=temp;
        }
      }
    }
    avgphval=0;
    for(int i=2;i<8;i++)
    avgphval+=buffer_arr[i];
    float volt=(float)avgphval*5.0/1024/6;
    pHLevel_Sensor.setData() = -5.70 * volt + calibration_value;
  }


  if (Waterlevel_Sensor.getData() < 100) {
    // masok air
  }
  

}
