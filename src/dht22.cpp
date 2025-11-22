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
    // Libraries
    dht.begin();
    // State
    status = Status::ON;
}

// State
DHTSensor::State DHTSensor::getState() const {
    return state;
}

void DHTSensor::setState(State newState) {
    state = newState;
}

// Read data
void DHTSensor::readTemp(){

    temp = dht.readTemperature();

    // Update state
    setState(State::READ);
}

void DHTSensor::readHumid(){

    humid = dht.readHumidity();

    // Update state
    setState(State::READ);
}

void DHTSensor::readTempAndHumid() {

    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (!isnan(t) && !isnan(h))
    {
        temp = t;
        humid = h;

        // Update state
        setState(State::READ);
    } else {
        // Update state
        state = DHTSensor::State::FAIL;
    }  
}

// Get data
float DHTSensor::getTemp(){
    return temp;
}

float DHTSensor::getHumid(){
    return humid;
}
