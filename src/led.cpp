// Header files
#include "led.h"

// Constructor
LED::LED(int led_pin): 
    // Pins
    LED_PIN(led_pin),
    
    // State
    state(State::INIT)
{}

// Initialization
void LED::begin(){
    pinMode(LED_PIN, OUTPUT);
    status = Status::ON;
}

// State
LED::State LED::getState() const {
    return state;
}