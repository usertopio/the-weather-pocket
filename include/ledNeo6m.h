#ifndef LEDNEO6M_H
#define LEDNEO6M_H

// Header files
#include "component.h"

class LedNeo6m : public Component {
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