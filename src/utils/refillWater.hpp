#ifndef RefillWaterFunc
    #define RefillWaterFunc
#endif

#ifndef _sensors
    #include <data/sensors.hpp>
#endif

#ifndef Arduino_h
#include <Arduino.h>
#endif

void refill_water() {
    digitalWrite(SupplyWaterRelay, HIGH);
    delay(1000);
    digitalWrite(SupplyWaterRelay, LOW);

}