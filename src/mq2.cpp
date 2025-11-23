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

// Status
const char* mq2StatusToString(Mq2::Status status) {
    switch (status) {
        case Mq2::Status::ON:  return "ON";
        case Mq2::Status::OFF: return "OFF";
        default: return "UNKNOWN";
    }
}

// State
Mq2::State Mq2::getState() const {
    return state;
}

void Mq2::setState(State newState) {
    state = newState;
}

const char* mq2StateToString(Mq2::State state) {
    switch (state) {
        case Mq2::State::INIT: return "INIT";
        case Mq2::State::READ: return "READ";
        case Mq2::State::FAIL: return "FAIL";
        default: return "RUN_OUT_OF_STATE";
    }
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