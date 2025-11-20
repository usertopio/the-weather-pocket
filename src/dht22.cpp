// Header files
#include "dht22.h"

// Constructor
DHTSensor::DHTSensor(int dht_pin) :
    // Pins
    DHT_PIN(dht_pin),

    // State
    state(State::INIT),

    // Library
    dht(dht_pin, DHT22)
{}

// Initialization
void DHTSensor::begin() {
    dht.begin();
    status = Status::ON;
}

// State
DHTSensor::State DHTSensor::getState() const {
    return state;
}
