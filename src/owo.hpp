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


// A0 = Analog Pin, 400 (nilai int) . 30
// D0 = Digital Pin, (nilai bool, boolean)


RTC_DS3231 rtc;
DateTime now;
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int lastWeek =  1000 * 60 * 60 * 24 * 7;
int lastTimeMeasuredAmmonia = 1636290751629 - lastWeek;

void setup() {
  // put your setup code here, to run once:

	pinMode(2, OUTPUT);

	pinMode(TDSensor_PIN, INPUT);
  pinMode(TemperatureSensor_PIN, INPUT);
  pinMode(22, INPUT); // 

  /* Relay Initialisation */
  pinMode(SupplyWaterRelay, INPUT); // relay for supplying water
  pinMode(waterPumpRelay, INPUT); // relay for water pump 

  pinMode(KettleRelay, INPUT); // relay for solenoid located at pipe to kettle 
  pinMode(PtRRelay, INPUT); // relay for solenoid located at pipe for removal (water)

  /* end of Relay Initialisation */

  sensors.begin(); 

	Serial.begin(9600);


  lcd.init();
  lcd.backlight();

  // pinMode(3, OUTPUT);

  // INISIALISASI RTC (REAL TIME CLOCK)
  if (!rtc.begin()) 
  {
    Serial.println("Couldn't find RTC Module");
    while (1)
      ;
  }

  if (rtc.lostPower()) 
  {
    Serial.println("RTC lost power, lets set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // INISIALISASI RTC (REAL TIME CLOCK)
}

void loop() {

  lcd.begin(20, 4);
  lcd.createChar(0, degreeIcon);
  lcd.createChar(1, christ);

  now = rtc.now(); 
  int hour = now.hour();
  int minute = now.minute();
  int unixTime = now.unixtime();

  int measurepHButton = digitalRead(22);


  // put your main code here, to run repeatedly:
  Waterlevel_Sensor.setData() = analogRead(waterLevelSensorPin);
  TDS_Sensor.setData() = analogRead(TDSensor_PIN);

  sensors.requestTemperatures();
  WaterTemperature_Sensor.setData() = sensors.getTempCByIndex(0);

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
    refill_water();
  }
  

  if (lastTimeMeasuredAmmonia >= unixTime) {
    digitalWrite(PtRRelay, LOW); // 
    digitalWrite(PtKRelay, HIGH); // 

    digitalWrite(waterPumpRelay, HIGH); // start taking water.
    delay(1000);
    digitalWrite(waterPumpRelay, LOW); // stop taking water
    digitalWrite(KettleRelay, HIGH); // turn on kettle, and start heating water
    delay(1000); // how long does the kettle will bubbles the water at certain amount of litres of water?
    digitalWrite(KettleRelay, LOW);

    digitalWrite(PtRRelay, LOW); // 
    digitalWrite(PtKRelay, LOW); // 


    /* MQ137 Initialisation */
    float VRL; //Voltage drop across the MQ sensor
    float rs; //Sensor resistance at gas concentration 
    float ratio; //Define variable for ratio
    
    VRL = analogRead(MQ_sensor)*(5.0/1023.0); //Measure the voltage drop and convert to 0-5V
    rs = ((5.0*RL)/VRL)-RL; //Use formula to get Rs value
    ratio = Rs/Ro;  // find ratio Rs/Ro

    float ppm = pow(10, ((log10(ratio)-b)/m)); //use formula to calculate ppm


    if (ppm >= 2) {
      waterChangeFunc();
    }

    MQ137_SENSOR.setData() = ppm; 
    MQ137_SENSOR.setCustomData() = VRL; 

    /* end of MQ137 initialization */

 
  }


}
