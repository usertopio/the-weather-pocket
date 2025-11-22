// Framework
#include <Arduino.h>

// Header files
#include "ledNeo6m.h"

// Constructor
LedNeo6m::LedNeo6m(int led_neo6m_pin): 
    // Pins
    LED_NEO6M_PIN(led_neo6m_pin),
    // State
    state(State::OFF)
{}

// Initialization
void LedNeo6m::begin(){
    // Pins
    pinMode(LED_NEO6M_PIN, OUTPUT);
    // State
    status = Status::ON;
}

// State
LedNeo6m::State LedNeo6m::getState() const {
    return state;
}

void LedNeo6m::setState(State newState) {
    state = newState;
}