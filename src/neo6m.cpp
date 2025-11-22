// Header files
// Child components
#include "neo6m.h"

// Constructor
Neo6m::Neo6m(int neo_rx, int neo_tx):
    // Pins
    NEO_RX(neo_rx),
    NEO_TX(neo_tx),
    // State
    state(State::INIT)
{}

// Initialization
void Neo6m::begin(){
    // Libraries
    gpsSerial.begin(9600, SERIAL_8N1, NEO_RX, NEO_TX);
    // State
    status = Status::ON;
}

// State
Neo6m::State Neo6m::getState() const {
    return state;
}

void Neo6m::setState(State newState) {
    state = newState;
}