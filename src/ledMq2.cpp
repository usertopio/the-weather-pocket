// Framework
#include <Arduino.h>

// Header files
// Child components
#include "ledMq2.h"

// Constructor
LedMq2::LedMq2(int led_mq2_pin): 
    // Pins
    LED_MQ2_PIN(led_mq2_pin),
    // State
    state(State::OFF)
{}

// Initialization
void LedMq2::begin(){
    // Pins
    pinMode(LED_MQ2_PIN, OUTPUT);
    // State
    status = Status::ON;
}

// State
LedMq2::State LedMq2::getState() const {
    return state;
}

void LedMq2::setState(State newState) {
    state = newState;
}