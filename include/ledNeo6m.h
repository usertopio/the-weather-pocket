#ifndef LEDMQ2_H
#define LEDMQ2_H

// Header files
#include "sensor.h"

class LedNeo6m : public Sensor {
public:
    // ===== Types & Enums =====
    // State
    enum class State {
        ON,
        OFF,
    };

    // ===== Constructor & Destructor =====
    LedNeo6m(int led_neo6m_pin);

    // ===== Public Methods =====
    // Initialization
    void begin();

    // State
    State getState() const;
    void setState(State newState); 

private:
    // ===== Pin Configuration =====
    const int LED_NEO6M_PIN;

    // ===== State Variables =====
    State state;
};

#endif