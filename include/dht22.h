#ifndef DHT22_H
#define DHT22_H

// Libraries
#include <DHT.h>

// Header files
#include "sensor.h"

class DHTSensor : public Sensor {
public:
    // ===== Types & Enums =====
    enum class State {
        INIT,
        MEASURE_TEMPERATURE,
        MEASURE_HUMIDITY
    };

    // ===== Constructor & Destructor =====
    DHTSensor(int dht_pin);

    // ===== Public Methods =====
    void begin() override;
    State getState() const;
    float readTemp();
    float readHumid();
    float getTemp();
    float getHumid();

private:
    // ===== Pin Configuration =====
    const int DHT_PIN;

    // ===== State Variables =====
    State state;

    // ===== Sensor Data =====
    DHT dht;

    float temp;
    float humid;
};

#endif