// Header files
// Child components
#include "dht22.h"

// Constructor
DhtSensor::DhtSensor(int dht_pin) :
    // Pins
    DHT_PIN(dht_pin),
    // State
    state(State::INIT),
    // Library
    dht(dht_pin, DHT22)
{}

// Initialization
void DhtSensor::begin() {
    // Libraries
    dht.begin();
    // State
    status = Status::ON;
}

// State
DhtSensor::State DhtSensor::getState() const {
    return state;
}

void DhtSensor::setState(State newState) {
    state = newState;
}

// Read data
void DhtSensor::readTemp(){

    temp = dht.readTemperature();

    // Update state
    setState(State::READ);
}

void DhtSensor::readHumid(){

    humid = dht.readHumidity();

    // Update state
    setState(State::READ);
}

void DhtSensor::readTempAndHumid() {

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
        state = DhtSensor::State::FAIL;
    }  
}

// Get data
float DhtSensor::getTemp(){
    return temp;
}

float DhtSensor::getHumid(){
    return humid;
}
