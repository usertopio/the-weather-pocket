// Framework
#include <Arduino.h>

// Header files
// Child components
#include "buttonOledDisplay.h"

// Constructor
ButtonOledDisplay::ButtonOledDisplay(int data_pin) :
    // Pins
    DATA_PIN(data_pin),
    // State
    state(State::NOT_PRESSED),

    lastButtonOledDisplayState(false)
{}

// Initialization
void ButtonOledDisplay::begin() {
    // Pins
    pinMode(DATA_PIN, INPUT_PULLUP);
    // State
    status = Status::ON;
}

// State
ButtonOledDisplay::State ButtonOledDisplay::getState() const {
    return state;
}

void ButtonOledDisplay::setState(State newState) {
    state = newState;
}