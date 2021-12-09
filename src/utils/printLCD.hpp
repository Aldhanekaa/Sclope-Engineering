#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef _printLCD
#define _printLCD
#endif

#ifndef _sensors
    #include <data/sensors.hpp>
#endif


// #ifndef _DHT_SENSOR_H
//   #include <sensors/DHT11_SENSOR.h>
// #endif

// DHT11_DATA Outside;
// DHT11_DATA Inside;
// DHT11_SENSOR_INSTANCE DHT11_SENSOR("DHT11",Outside,Inside);

// Sensor<int, int> SunlightIntensity("sunlight_intensity", -1, -1);
// Sensor<int, int> SoilMoisture("soil_moisture", -1, -1);

void show_temperature_humidity();

enum LCD_Tasks
{
  temp_and_tds = 't_tds',
  waterLvl = 'ss',
    pH = 'pH',

};

LCD_Tasks nextShow = waterLvl;
int lastShowInSeconds = -1;

void printLCD(int second) {
    if (lastShowInSeconds==-1) {
        lastShowInSeconds=second;
    }

    if (second == 59) {
        lastShowInSeconds = 0;
    }

     // Print 'Hello World!' on the first line of the LCD:
            // lcd.setCursor(0, 0); // Set the cursor on the first column and first row.(7->column, 0->row)

            // lcd.print("ceres-n-meses.now.sh        "); // Print the string "Hello World!"
        // Serial.println(Seconds );
        // Serial.println(lastShowInSeconds );
    // Serial.println(lastShowInSeconds);

    // Serial.println(second);

    if ((second - lastShowInSeconds) <= (second))
    {
        switch (nextShow)
        {
        case temp_and_tds:
            // lcd.clear();
            lcd.setCursor(0, 1); // Set the cursor on the first column and first row.(7->column, 0->row)

            lcd.print("Temperature: "); // Print the string "Hello World!"
            lcd.print(WaterTemperature_Sensor.getData());
            lcd.write(1);

            lcd.setCursor(0, 2); // Set the cursor on the first column and first row.(7->column, 0->row)
            lcd.print("TDS Sensor: "); // Print the string "Hello World!"
            lcd.print(TDS_Sensor.getData());
            lcd.write(" ppm");

            // DHT11_SENSOR.getDataInside().humidity;
            nextShow = waterLvl;
            /* code */
            break;
        
        case waterLvl: 

            lcd.setCursor(0, 1); // Set the cursor on the first column and first row.(7->column, 0->row)

            lcd.print("Water Level: "); // Print the string "Hello World!"
            lcd.print(Waterlevel_Sensor.getData()); // Print the string "Hello World!"

            lcd.setCursor(0, 2); // Set the cursor on the first column and first row.(7->column, 0->row)
            lcd.print(" "); // Print the string "Hello World!"
  
        //   // Print 'Hello World!' on the first line of the LCD:
        //     lcd.setCursor(0, 0); // Set the cursor on the first column and first row.(7->column, 0->row)

        //     lcd.print("ceres-n-meses.now.sh        "); // Print the string "Hello World!"
            
        //     lcd.setCursor(0, 1); //Set the cursor on the third column and the second row (counting starts at 0!).row 1
        //     for (int i = 1; i <= 20; i++)
        //     {
        //         lcd.print("-");
        //     }

        //     lcd.setCursor(0, 2); //Set the cursor on the third column and the second row (counting starts at 0!).row 1
        //     lcd.print("Soil Moisture: ");
        //     lcd.print(String(SoilMoisture.getDataInside()));
        //     lcd.print("%");

        //     lcd.setCursor(0, 3); //Set the cursor on the third column and the second row (counting starts at 0!).row 1
        //     lcd.print("Sunlight: ");
        //     lcd.print(String(SunlightIntensity.getDataInside()));
        //     lcd.print("%");

                // DHT11_SENSOR.getDataInside().humidity;
            nextShow = pH;
            /* code */
            break;
        case pH: 

            lcd.setCursor(0, 1); // Set the cursor on the first column and first row.(7->column, 0->row)

            lcd.print("pH: "); // Print the string "Hello World!"
            lcd.print(pHLevel_Sensor.getData()); // Print the string "Hello World!"

            lcd.setCursor(0, 2); // Set the cursor on the first column and first row.(7->column, 0->row)
            lcd.print(" "); // Print the string "Hello World!"
  
        //   // Print 'Hello World!' on the first line of the LCD:
        //     lcd.setCursor(0, 0); // Set the cursor on the first column and first row.(7->column, 0->row)

        //     lcd.print("ceres-n-meses.now.sh        "); // Print the string "Hello World!"
            
        //     lcd.setCursor(0, 1); //Set the cursor on the third column and the second row (counting starts at 0!).row 1
        //     for (int i = 1; i <= 20; i++)
        //     {
        //         lcd.print("-");
        //     }

        //     lcd.setCursor(0, 2); //Set the cursor on the third column and the second row (counting starts at 0!).row 1
        //     lcd.print("Soil Moisture: ");
        //     lcd.print(String(SoilMoisture.getDataInside()));
        //     lcd.print("%");

        //     lcd.setCursor(0, 3); //Set the cursor on the third column and the second row (counting starts at 0!).row 1
        //     lcd.print("Sunlight: ");
        //     lcd.print(String(SunlightIntensity.getDataInside()));
        //     lcd.print("%");

                // DHT11_SENSOR.getDataInside().humidity;
            nextShow = temp_and_tds;
            /* code */
            break;
        default:
            break;
        }

        lastShowInSeconds = second;
    }
}

// void show_temperature_humidity() {
// // Serial.println("waterLvl");

//     lcd.setCursor(0, 0); 

//     lcd.print("Ceres N Meses        "); 

//     lcd.setCursor(0, 1);
//     for (int i = 1; i <= 20; i++)
//     {
//         lcd.print("-");
//     }

//     lcd.setCursor(0, 2);
//     lcd.print("Temperature: ");
//     lcd.print(String(DHT11_SENSOR.getDataInside().temperature));
//     lcd.write(0);
//     lcd.print("C");

//     lcd.setCursor(0, 3);
//     lcd.print("Humidity: ");
//     lcd.print(String(DHT11_SENSOR.getDataInside().humidity));
//     lcd.print("%");
// }