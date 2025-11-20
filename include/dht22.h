#ifndef DHT22_H
#define DHT22_H

// Libraries
#include <DHT.h>

// Header files
#include "sensor.h"

class DHT22 : public Sensor {
public:
    // ===== Types & Enums =====
    enum class State {
        INIT,
        MEASURE_TEMPERATURE,
        MEASURE_HUMIDITY
    };

    // ===== Constructor & Destructor =====
    DHT22(int dht_pin);

    // ===== Public Methods =====
    void begin() override;
    State getState() const;

private:
    // ===== Pin Configuration =====
    const int DHT_PIN;

    // ===== State Variables =====
    State state;

    // ===== Sensor Data =====
    DHT dht;
};

#endif