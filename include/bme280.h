#ifndef BME280_H
#define BME280_H

// Libraries
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Header files
#include <sensor.h>

class BME280 : public Sensor {
    // Constructor
    public:
        // Methods
        BME280(int bme_mosi, int bme_miso, int bme_scl, int bme_cs);
    
    // Initialization
    public:
        // Methods
        void begin() override;

    // Pins
    private:
        // Variables
        const int BME_MOSI; // SDA
        const int BME_MISO; // SDO
        const int BME_SCK; // SCL
        const int BME_CS; // CSB

    // State
    protected:
        // Variables
        enum class State {
            INIT,
            MEASURE_TEMPERATURE,
            MEASURE_HUMIDITY,
            MEASURE_PRESSURE,
            CALCULATE_ALTITUDE
        };
  
        State state;
    public:
        // Methods
        State getState() const;

    // Data
    private:
        // Variables
        // Library constants
        Adafruit_BME280 bme;
        // My data
        const int SEA_LEVEL_PRESSURE_HPA;
    };

#endif