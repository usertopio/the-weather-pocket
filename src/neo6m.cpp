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

// Status
const char* neo6mStatusToString(Neo6m::Status status) {
    switch (status) {
        case Neo6m::Status::ON:  return "ON";
        case Neo6m::Status::OFF: return "OFF";
        default: return "UNKNOWN";
    }
}

// State
Neo6m::State Neo6m::getState() const {
    return state;
}

void Neo6m::setState(State newState) {
    state = newState;
}

const char* neo6mStateToString(Neo6m::State state) {
    switch (state) {
        case Neo6m::State::INIT: return "INIT";
        case Neo6m::State::WAIT_FOR_FIX: return "WAIT_FOR_FIX";
        case Neo6m::State::GOT_FIX: return "GOT_FIX";
        default: return "RUN_OUT_OF_STATE";
    }
}

// Read data
void Neo6m::read(){

    // #17
    readLocation();
    readDateAndTime();
    readAccuracy();

    // Update state
    setState(State::GOT_FIX);
}

void Neo6m::readLocation(){

    if (gps.location.isValid()) {
        
        location.latitude = gps.location.lat();

        // Update state
        setState(State::GOT_FIX);
    } else {
        // Update state
        setState(State::WAIT_FOR_FIX);
    }
}

void Neo6m::readDateAndTime(){

    if (gps.location.isValid()) {
        
        dateAndTime.year  = gps.date.year();
        dateAndTime.month = gps.date.month();
        dateAndTime.day   = gps.date.day();

        dateAndTime.hour  = gps.time.hour();
        dateAndTime.minute = gps.time.minute();
        dateAndTime.second   = gps.time.second();

        // Update state
        setState(State::GOT_FIX);
    } else {
        // Update state
        setState(State::WAIT_FOR_FIX);
    }
}

void Neo6m::readAccuracy(){

    if (gps.location.isValid()) {
        
        accuracy.amount_of_satellite  = gps.satellites.value();
        accuracy.hdop = gps.hdop.value();

        // Update state
        setState(State::GOT_FIX);
    } else {
        // Update state
        setState(State::WAIT_FOR_FIX);
    }
}

// Get data
float Neo6m::getLatitude(){
    return location.latitude;
}

float Neo6m::getLongitude(){
    return location.longitude;
}

float Neo6m::getAltitude(){
    return location.altitude;
}

float Neo6m::getSpeed(){
    return location.speed;
}

int Neo6m::getYear(){
    return dateAndTime.year;
}

int Neo6m::getMonth(){
    return dateAndTime.month;
}

int Neo6m::getDay(){
    return dateAndTime.day;
}

int Neo6m::getHour(){
    return dateAndTime.day;
}

int Neo6m::getMinute(){
    return dateAndTime.day;
}

int Neo6m::getSecond(){
    return dateAndTime.day;
}

int Neo6m::getAmountOfSat(){
    return accuracy.amount_of_satellite;
}

int Neo6m::getHDOP(){
    return accuracy.hdop;
}
