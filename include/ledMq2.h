#ifndef LEDMQ2_H
#define LEDMQ2_H

// Header files
#include "component.h"

class LedMQ2 : public Component {
public:
    // State
    enum class State {
        ON,
        OFF,
    };

    // Constructor
    LedMQ2(int led_mq2_pin);

    //  Initialization
    void begin();

    // State
    State getState() const;
    void setState(State newState); 

private:
    // Pins
    const int LED_MQ2_PIN;

    // State
    State state;
};

#endif