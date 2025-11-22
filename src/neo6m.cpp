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

// Read data
void Neo6m::readData(){

    // #17

    // Update state
    setState(State::GOT_FIX);
}

// Get data
float Neo6m::getLatitude(){
    return latitude;
}

float Neo6m::getLongitude(){
    return longitude;
}

float Neo6m::getAltitude(){
    return altitude;
}

float Neo6m::getDate(){
    return date;
}

float Neo6m::getTime(){
    return time;
}

float Neo6m::getSpeed(){
    return speed;
}

float Neo6m::getAmountOfSat(){
    return amount_of_satellite;
}

float Neo6m::getHDOP(){
    return hdop;
}
