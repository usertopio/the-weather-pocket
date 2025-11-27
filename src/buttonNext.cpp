// Framework
#include <Arduino.h>

// Header files
// Child components
#include "buttonNext.h"

// Constructor
ButtonNext::ButtonNext(int data_signal) :
    // Pins
    DATA_SIGNAL(data_signal),
    // State
    state(State::NOT_PRESSED),

    // Data
    // My data
    isPressed(false)
{}

// Initialization
void ButtonNext::begin() {
    // Pins
    pinMode(DATA_SIGNAL, INPUT);  // Use INPUT for external pull-up
    // Read the initial state of the pin
    lastButtonNextState = digitalRead(DATA_SIGNAL);
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
    currentButtonNextState = digitalRead(DATA_SIGNAL);
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