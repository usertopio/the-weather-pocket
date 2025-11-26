// Framework
#include <Arduino.h>

// Header files
// Child components
#include "buttonConfirm.h"

// Constructor
ButtonConfirm::ButtonConfirm(int signal_pin) :
    // Pins
    SIGNAL_PIN(signal_pin),
    // State
    state(State::NOT_PRESSED),

    lastButtonConfirmState(false)
{}

// Initialization
void ButtonConfirm::begin() {
    // Pins
    pinMode(SIGNAL_PIN, INPUT_PULLUP);
    // State
    status = Status::ON;
}

// State
ButtonConfirm::State ButtonConfirm::getState() const {
    return state;
}

void ButtonConfirm::setState(State newState) {
    state = newState;
}