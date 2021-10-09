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

#include <Arduino.h>
#define sensorPin A0

// A0 = Analog Pin, 400 (nilai int) . 30
// D0 = Digital Pin, (nilai bool, boolean)

void setup() {
  // put your setup code here, to run once:

	pinMode(2, OUTPUT);


	Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nilaiWaterLevel = analogRead(sensorPin);		// Read the analog value form sensor

  Serial.println(nilaiWaterLevel);

  if (nilaiWaterLevel < 100) {
    // masok air
  }

}
