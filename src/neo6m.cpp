// Header files
#include "neo6m.h"

// Constructor
NEO6M::NEO6M(int neo_rx, int neo_tx):
    // Pins
    NEO_RX(neo_rx),
    NEO_TX(neo_tx),
    // State
    state(State::INIT)
{}

// Initialization
void NEO6M::begin(){
    // Libraries
    gpsSerial.begin(9600, SERIAL_8N1, NEO_RX, NEO_TX);
    // State
    status = Status::ON;
}

// State
NEO6M::State NEO6M::getState() const {
    return state;
}

void NEO6M::setState(State newState) {
    state = newState;
}