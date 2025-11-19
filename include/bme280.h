#ifndef BME280_H
#define BME280_H

// Libraries
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Header files
#include <sensor.h>

class BME280 : public Sensor {
    private:
        const int BME_MOSI; // SDA
        const int BME_MISO; // SDO
        const int BME_SCK; // SCL
        const int BME_CS; // CSB

        const int SEA_LEVEL_PRESSURE_HPA;

        Adafruit_BME280 bme;
    public:
        BME280(int bme_mosi, int bme_miso, int bme_scl, int bme_cs);
        void begin() override;
    };

#endif