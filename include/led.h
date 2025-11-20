#ifndef LED_H
#define LED_H

// Header files
#include "sensor.h"

class LED : public Sensor {
public:
    // ===== Types & Enums =====
    enum class State {
        INIT,
        OFF,
        ON,
        BLINK
    };

    // ===== Constructor & Destructor =====
    LED(int led_pin);

    // ===== Public Methods =====
    void begin();
    State getState() const;

private:
    // ===== Pin Configuration =====
    const int LED_PIN;

    // ===== State Variables =====
    State state;
};

#endif