#ifndef BME280_H
#define BME280_H

// Libraries
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Header files
// Parent components
#include "component.h"

class Bme280 : public Component {
    public:
        // State
        enum class State {
            INIT,
            READ,
            FAIL
        };

        // Constructor
        Bme280(int bme_mosi, int bme_miso, int bme_scl, int bme_cs, float sea_level_pressure_hpa);

        //  Initialization
        void begin() override;

        // State
        State getState() const;
        void setState(State newState); 

        // Read data
        void read();
        void readTemp();
        void readHumid();
        void readPressure();
        void readAltitude();

        // Get data
        float getTemp();
        float getHumid();
        float getRawPressure();
        float getPressure();
        float getAltitude();

    private:
        // Pins
        const int BME_MOSI; // SDA
        const int BME_MISO; // SDO
        const int BME_SCK;  // SCL
        const int BME_CS;   // CSB

        // State
        State state;

        // Data
        // Libraries
        Adafruit_BME280 bme;
        // My data
        float temp;
        float humid;
        float rawPressure;
        float pressure;
        float altitude;
        const int SEA_LEVEL_PRESSURE_HPA;
};

// Status
const char* bme280StatusToString(Bme280::Status status);

// State
const char* bme280StateToString(Bme280::State state);


#endif