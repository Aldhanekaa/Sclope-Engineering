#ifndef Arduino_h
#include <Arduino.h>
#endif

#define _sensor

template<typename DATA_TYPENAME,typename CUSTOM_DATA_TYPENAME> 
class Sensor {    
    protected:
        DATA_TYPENAME Inside;
        String SensorName;
        CUSTOM_DATA_TYPENAME customData;

    public:
        Sensor(String SensorName, DATA_TYPENAME Inside) {
            this->SensorName = SensorName;
            this->Inside = Inside;
        }

        DATA_TYPENAME& setData() {
            return this->Inside;
        }
        

        DATA_TYPENAME getData() {
            return this->Inside;
        }

        CUSTOM_DATA_TYPENAME& setCustomData() {
            return this->customData;
        }

        CUSTOM_DATA_TYPENAME getCustomData() {
            return this->customData;
        }

};