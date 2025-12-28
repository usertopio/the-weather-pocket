// Header files
#include "neo6m.h"

// Constructor
Neo6m::Neo6m(int neo_rx, int neo_tx)
    : NEO_RX(neo_rx), NEO_TX(neo_tx), state(State::INIT)
{}

// Initialization
void Neo6m::begin() {
    gpsSerial.begin(9600, SERIAL_8N1, NEO_RX, NEO_TX);
    status = Status::ON;    // from Component base class
}

// State
Neo6m::State Neo6m::getState() const {
    return state;
}

void Neo6m::setState(State newState) {
    state = newState;
}

// State to string
const char* neo6mStateToString(Neo6m::State state) {
    switch (state) {
        case Neo6m::State::INIT:         return "INIT";
        case Neo6m::State::WAIT_FOR_FIX: return "WAIT_FOR_FIX";
        case Neo6m::State::GOT_FIX:      return "GOT_FIX";
        default: return "UNKNOWN_STATE";
    }
}

// Read data
void Neo6m::read() {
    int charsProcessed = 0;
    
    while (gpsSerial.available()) {
        char c = gpsSerial.read();
        gps.encode(c);
        charsProcessed++;
    }

    // Debug: Print how many characters were processed
    if (charsProcessed > 0) {
        Serial.print("GPS chars processed: ");
        Serial.println(charsProcessed);
    }

    // Debug: Print satellite count
    Serial.print("Satellites: ");
    Serial.println(gps.satellites.value());
    
    Serial.print("Characters received: ");
    Serial.println(gps.charsProcessed());
    
    Serial.print("Sentences with fix: ");
    Serial.println(gps.sentencesWithFix());
    
    Serial.print("Failed checksum: ");
    Serial.println(gps.failedChecksum());

    // Fix detection
    if (gps.location.isValid()) {
        setState(State::GOT_FIX);
        readLocation();
        Serial.println("*** GOT GPS FIX ***");
    } else {
        setState(State::WAIT_FOR_FIX);
        Serial.println("Waiting for GPS fix...");
    }

    // ALWAYS call — inside the function validity is checked
    readDateAndTime();

    // ALWAYS call accuracy
    readAccuracy();
}

void Neo6m::readLocation() {
    location.latitude  = gps.location.lat();
    location.longitude = gps.location.lng();
    location.altitude  = gps.altitude.meters();
    location.speed     = gps.speed.kmph();
    location.course    = gps.course.deg();
}

void Neo6m::readDateAndTime() {
    if (gps.date.isValid()) {
        dateAndTime.year  = gps.date.year();
        dateAndTime.month = gps.date.month();
        dateAndTime.day   = gps.date.day();
    }

    if (gps.time.isValid()) {
        dateAndTime.hour   = gps.time.hour();
        dateAndTime.minute = gps.time.minute();
        dateAndTime.second = gps.time.second();
    }
}

void Neo6m::readAccuracy() {
    accuracy.amount_of_satellite = gps.satellites.value();
    accuracy.hdop = gps.hdop.hdop();
}

// Getters
float Neo6m::getLatitude() { return location.latitude; }
float Neo6m::getLongitude() { return location.longitude; }
float Neo6m::getAltitude() { return location.altitude; }
float Neo6m::getSpeed() { return location.speed; }
float Neo6m::getCourse() { return location.course; }

int Neo6m::getYear() { return dateAndTime.year; }
int Neo6m::getMonth() { return dateAndTime.month; }
int Neo6m::getDay() { return dateAndTime.day; }

int Neo6m::getHour() { return dateAndTime.hour; }
int Neo6m::getMinute() { return dateAndTime.minute; }
int Neo6m::getSecond() { return dateAndTime.second; }

int Neo6m::getAmountOfSat() { return accuracy.amount_of_satellite; }
float Neo6m::getHDOP() { return accuracy.hdop; }
