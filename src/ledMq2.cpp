// Framework
#include <Arduino.h>

// Header files
#include "ledMq2.h"

// Constructor
LedMQ2::LedMQ2(int led_mq2_pin): 
    // Pins
    LED_MQ2_PIN(led_mq2_pin),
    
    // State
    state(State::INIT)
{}

// Initialization
void LedMQ2::begin(){
    pinMode(LED_MQ2_PIN, OUTPUT);
    status = Status::ON;
}

// State
LedMQ2::State LedMQ2::getState() const {
    return state;
}