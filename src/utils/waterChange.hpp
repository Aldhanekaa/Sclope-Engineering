#ifndef WaterChangeFunc
    #define WaterChangeFunc
#endif

#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef _sensors
    #include <data/sensors.hpp>
#endif

#ifndef RefillWaterFunc
    #include <utils/refillWater.hpp>
#endif


void waterChangeFunc() {
    // digitalWrite(PtRRelay, HIGH); // 
    // digitalWrite(PtKRelay, LOW); // 

    digitalWrite(waterPumpRelay, HIGH); // start taking water.
    delay(1000);
    digitalWrite(waterPumpRelay, LOW); // stop taking water

    // digitalWrite(PtRRelay, LOW); // 
    // digitalWrite(PtKRelay, LOW); // 
    refill_water();
}