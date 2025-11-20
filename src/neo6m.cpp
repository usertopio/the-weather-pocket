// Header files
#include "neo6m.h"

// Constructor
NEO6M::NEO6M(HardwareSerial &serial):
    // Pins
    gpsSerial(serial),

    // State
    state(State::INIT)
{}

// Initialization
void NEO6M::begin(){
    gpsSerial.begin(9600);
    status = Status::ON;
}

// State
NEO6M::State NEO6M::getState() const {
    return state;
}