#ifndef LEDMQ2_H
#define LEDMQ2_H

// Header files
#include "sensor.h"

class LedMQ2 : public Sensor {
public:
    // ===== Types & Enums =====
    // State
    enum class State {
        ON,
        OFF,
    };

    // ===== Constructor & Destructor =====
    LedMQ2(int led_mq2_pin);

    // ===== Public Methods =====
    // Initialization
    void begin();

    // State
    State getState() const;
    void setState(State newState); 

private:
    // ===== Pin Configuration =====
    const int LED_MQ2_PIN;

    // ===== State Variables =====
    State state;
};

#endif