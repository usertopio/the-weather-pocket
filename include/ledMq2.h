#ifndef LEDMQ2_H
#define LEDMQ2_H

// Header files
#include "sensor.h"

class LedMQ2 : public Sensor {
public:
    // ===== Types & Enums =====
    enum class State {
        INIT,
        OFF,
        ON,
        BLINK
    };

    // ===== Constructor & Destructor =====
    LedMQ2(int led_mq2_pin);

    // ===== Public Methods =====
    void begin();
    State getState() const;

private:
    // ===== Pin Configuration =====
    const int LED_MQ2_PIN;

    // ===== State Variables =====
    State state;
};

#endif