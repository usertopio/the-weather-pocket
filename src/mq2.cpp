// Framework
#include <Arduino.h>

// Header files
// Child components
#include "mq2.h"

// Constructor
Mq2::Mq2(int data_pin) :
    // Pins
    DATA_PIN(data_pin),
    // State
    state(State::INIT)
{}

// Initialization
void Mq2::begin() {
    // State
    status = Status::ON;
}

// State
Mq2::State Mq2::getState() const {
    return state;
}

void Mq2::setState(State newState) {
    state = newState;
}

// Read data
void Mq2::readGas(){

    gas = digitalRead(DATA_PIN);

    // Update state
    setState(State::READ);
}



// Get data
float Mq2::getGas(){
    return gas;
}