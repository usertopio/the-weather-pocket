// Framework
#include <Arduino.h>

// Header files
// Child components
#include "buttonNext.h"

// Constructor
ButtonNext::ButtonNext(int data_pin) :
    // Pins
    DATA_PIN(data_pin),
    // State
    state(State::NOT_PRESSED),

    lastButtonNextState(false)
{}

// Initialization
void ButtonNext::begin() {
    // Pins
    pinMode(DATA_PIN, INPUT_PULLUP);
    // State
    status = Status::ON;
}

// State
ButtonNext::State ButtonNext::getState() const {
    return state;
}

void ButtonNext::setState(State newState) {
    state = newState;
}