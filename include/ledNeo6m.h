#ifndef LEDMQ2_H
#define LEDMQ2_H

// Header files
#include "sensor.h"

class LedNeo6m : public Sensor {
public:
    // State
    enum class State {
        ON,
        OFF,
    };

    // Constructor
    LedNeo6m(int led_neo6m_pin);

    // Initialization
    void begin();

    // State
    State getState() const;
    void setState(State newState); 

private:
    // Pins
    const int LED_NEO6M_PIN;

    // State
    State state;
};

#endif