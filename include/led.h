#ifndef LED_H
#define LED_H

// Libraries
#include <Arduino.h>

// Header files
#include "sensor.h"

class LED : public Sensor {
    // Constructor
    public:
        // Methods
        LED(int led_pin);

    // Initialization
    public:
        // Methods
        void begin() override;

    // Pins
    private:
        // Variables
        const int LED_PIN;

    // State
    protected:
        // Variables
        enum class State {
            INIT,
            ON,
            OFF
        };
  
        State state;

    public:
        // Methods
        State getState() const;
};

#endif