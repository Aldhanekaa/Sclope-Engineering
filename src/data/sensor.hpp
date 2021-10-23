#ifndef Arduino_h
#include <Arduino.h>
#endif

#define _sensor

template<typename INSIDE_TYPENAME> 
class Sensor {    
    protected:
        INSIDE_TYPENAME Inside;
        String SensorName;

    public:
        Sensor(String SensorName, INSIDE_TYPENAME Inside) {
            this->SensorName = SensorName;
            this->Inside = Inside;
        }

        INSIDE_TYPENAME& setDataInside() {
            return this->Inside;
        }
        

        INSIDE_TYPENAME getDataInside() {
            return this->Inside;
        }

};