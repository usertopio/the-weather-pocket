// Framework
#include <Arduino.h>

// Header files
// Child components
#include "buttonWifi.h"

// Constructor
ButtonWifi::ButtonWifi(int signal_pin) :
    // Pins
    SIGNAL_PIN(signal_pin),
    // State
    state(State::NOT_PRESSED),

    lastButtonWifiState(false)
{}

// Initialization
void ButtonWifi::begin() {
    // Pins
    pinMode(SIGNAL_PIN, INPUT_PULLUP);
    // State
    status = Status::ON;
}

// State
ButtonWifi::State ButtonWifi::getState() const {
    return state;
}

void ButtonWifi::setState(State newState) {
    state = newState;
}