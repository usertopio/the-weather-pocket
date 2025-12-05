// Framework
#include <Arduino.h>

// Header files
// Child components
#include "buttonNext.h"

// Constructor
ButtonNext::ButtonNext(int signal_pin) :
    // Pins
    SIGNAL_PIN(signal_pin),
    // State
    state(State::NOT_PRESSED),

    // Data
    // My data
    isPressed(false)
{}

// Initialization
void ButtonNext::begin() {
    // Pins
    pinMode(SIGNAL_PIN, INPUT);  // Use INPUT for external pull-up
    // Read the initial state of the pin
    lastButtonNextState = digitalRead(SIGNAL_PIN);
    currentButtonNextState = lastButtonNextState;
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

bool ButtonNext::isButtonNextPressed() {
    isPressed = false;
    // Detect button press (HIGH → LOW)
    if (lastButtonNextState == HIGH && currentButtonNextState == LOW) {
        setState(State::PRESSED);
        Serial.println("Next button pressed!");
        isPressed = true;
    }

    // Detect button release (LOW → HIGH)
    if (lastButtonNextState == LOW && currentButtonNextState == HIGH) {
        Serial.println("Next button released!");
        if (getState() == State::PRESSED) {
            Serial.println(">>> Action triggered once!");
            setState(State::NOT_PRESSED);
        }
    }

    lastButtonNextState = currentButtonNextState;
    return isPressed;
}

// Read signal
void ButtonNext::readSignal(){
    currentButtonNextState = digitalRead(SIGNAL_PIN);
}

// Get signal
bool ButtonNext::getButtonFlag(){
    return isPressed;
}

bool ButtonNext::getLastButtonNextState(){
    return lastButtonNextState;
}

bool ButtonNext::getCurrentButtonNextState(){
    return currentButtonNextState;
}