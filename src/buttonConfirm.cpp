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

    // Data
    // My data
    isPressed(false)
{}

// Initialization
void ButtonConfirm::begin() {
    // Pins
    pinMode(SIGNAL_PIN, INPUT);  // Use INPUT for external pull-up
    // Read the initial state of the pin
    lastButtonConfirmState = digitalRead(SIGNAL_PIN);
    currentButtonConfirmState = lastButtonConfirmState;
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

bool ButtonConfirm::isButtonConfirmPressed() {
    isPressed = false;
    // Detect button press (HIGH → LOW)
    if (lastButtonConfirmState == HIGH && currentButtonConfirmState == LOW) {
        setState(State::PRESSED);
        Serial.println("Confirm button pressed!");
        isPressed = true;
    }

    // Detect button release (LOW → HIGH)
    if (lastButtonConfirmState == LOW && currentButtonConfirmState == HIGH) {
        Serial.println("Confirm button released!");
        if (getState() == State::PRESSED) {
            Serial.println(">>> Action triggered once!");
            setState(State::NOT_PRESSED);
        }
    }

    lastButtonConfirmState = currentButtonConfirmState;
    return isPressed;
}

// Read signal
void ButtonConfirm::readSignal(){
    currentButtonConfirmState = digitalRead(SIGNAL_PIN);
}

// Get signal
bool ButtonConfirm::getButtonFlag(){
    return isPressed;
}

bool ButtonConfirm::getLastButtonConfirmState(){
    return lastButtonConfirmState;
}

bool ButtonConfirm::getCurrentButtonConfirmState(){
    return currentButtonConfirmState;
}