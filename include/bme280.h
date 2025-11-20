#ifndef BME280_H
#define BME280_H

// Libraries
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Header files
#include "sensor.h"

class BME280 : public Sensor {
public:
    // ===== Types & Enums =====
    enum class State {
        INIT,
        MEASURE_TEMPERATURE,
        MEASURE_HUMIDITY,
        MEASURE_PRESSURE,
        CALCULATE_ALTITUDE
    };

    // ===== Constructor & Destructor =====
    BME280(int bme_mosi, int bme_miso, int bme_scl, int bme_cs);

    // ===== Public Methods =====
    void begin() override;
    State getState() const;

private:
    // ===== Pin Configuration =====
    const int BME_MOSI; // SDA
    const int BME_MISO; // SDO
    const int BME_SCK;  // SCL
    const int BME_CS;   // CSB

    // ===== State Variables =====
    State state;

    // ===== Sensor Data =====
    Adafruit_BME280 bme;
    const int SEA_LEVEL_PRESSURE_HPA;
};

#endif