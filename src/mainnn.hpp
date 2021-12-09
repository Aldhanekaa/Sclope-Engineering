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
#include <Wire.h> // Library for I2C communication
#include <TM1637Display.h>

// A0 = Analog Pin, 400 (nilai int) . 30
// D0 = Digital Pin, (nilai bool, boolean)


RTC_DS3231 rtc;
DateTime now;
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int lastWeek =  1000 * 60 * 60 * 24 * 7;
int lastTimeMeasuredAmmonia = 1636290751629 - lastWeek;

// Define the connections pins for TM1637 4 digit 7 segment display
#define CLK 41
#define DIO 39

TM1637Display display = TM1637Display(CLK, DIO);

void setup() {

  Wire.begin();


  // put your setup code here, to run once:

	pinMode(2, OUTPUT);

	pinMode(TDSensor_PIN, INPUT);
  pinMode(TemperatureSensor_PIN, INPUT);
  pinMode(22, INPUT); // 

  /* Relay Initialisation */
  pinMode(SupplyWaterRelay, OUTPUT); // relay for supplying water
  pinMode(waterPumpRelay, OUTPUT); // relay for water pump 

  pinMode(KettleRelay, INPUT); // relay for solenoid located at pipe to kettle 

  /* end of Relay Initialisation */

  sensors.begin(); 

	Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  pinMode(3, OUTPUT);

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


  // Set the display brightness (0-7):
  display.setBrightness(5);
  // Clear the display:
  display.clear();
}


void loop() {

  // Get current date and time
  DateTime now = rtc.now();

  // Create time format to display:
  int displaytime = (now.hour() * 100) + now.minute();


  // Display the current time in 24 hour format with leading zeros enabled and a center colon:
  display.showNumberDecEx(displaytime, 0b11100000, true);


  now = rtc.now(); 
  int hour = now.hour();
  int minute = now.minute();
  int second = now.second();
  int year = now.year();

  // int measurepHButton = digitalRead(22);

  // put your main code here, to run repeatedly:
  Waterlevel_Sensor.setData() = analogRead(waterLevelSensorPin);

  // Send the command to get temperatures
  sensors.requestTemperatures(); 
  WaterTemperature_Sensor.setData() = sensors.getTempCByIndex(0);


  lcd.begin(20, 4);
  lcd.createChar(0, loveIcon);
  lcd.createChar(1, degreeIcon);

  lcd.setCursor(0, 0); // Set the cursor on the first column and first row.(7->column, 0->row)

  lcd.print("Sclope Engineering");

  lcd.setCursor(0, 3); // Set the cursor on the first column and first row.(7->column, 0->row)

  lcd.print("by ------ AAJKNSS");
  printLCD(second);


  // //print the temperature in Celsius
  // Serial.print("Temperature: ");
  // Serial.print(WaterTemperature_Sensor.getData());
  // Serial.print((char)176);//shows degrees character
  // Serial.print("C  |  ");
  
  // //print the temperature in Fahrenheit
  // Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
  // Serial.print((char)176);//shows degrees character
  // Serial.println("F");
    

  // // // TDS_Sensor.setData() = analogRead(TDSensor_PIN);
  // lcd.setCursor(0, 0); // Set the cursor on the first column and first row.(7->column, 0->row)

  // {"s", "c", "l", "o", "p", "e"}
  

  // lcd.print(" ");
  // lcd.write(0); 
 
  for(int i=0;i<10;i++) { 
      buffer_arr[i]=analogRead(A2);
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
    for(int i=2;i<8;i++) { avgphval+=buffer_arr[i]; }
    float volt=(float)avgphval*5.0/1024/6;
    pHLevel_Sensor.setData() = (-5.70 * volt + calibration_value) * -1;
    Serial.print("pH: ");
    Serial.println(pHLevel_Sensor.getData());
  // digitalWrite(waterPumpRelay, HIGH);
  // delay(1000);
    digitalWrite(SupplyWaterRelay, HIGH);
  delay(1000);
    digitalWrite(SupplyWaterRelay, LOW);

  // int measurings=0;

  //   for (int i = 0; i < samples; i++)
  //   {
  //       measurings += analogRead(pHSense);
  //       delay(10);

  //   }

  //   float voltage = 5 / adc_resolution * measurings/samples;
  //   Serial.print("pH= ");
  //   Serial.println(ph(voltage));
    delay(1000);


}
