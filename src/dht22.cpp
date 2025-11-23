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

// Status
const char* dht22StatusToString(DhtSensor::Status status) {
    switch (status) {
        case DhtSensor::Status::ON:  return "ON";
        case DhtSensor::Status::OFF: return "OFF";
        default: return "UNKNOWN";
    }
}

// State
DhtSensor::State DhtSensor::getState() const {
    return state;
}

void DhtSensor::setState(State newState) {
    state = newState;
}

const char* dht22StateToString(DhtSensor::State state) {
    switch (state) {
        case DhtSensor::State::INIT: return "INIT";
        case DhtSensor::State::READ: return "READ";
        case DhtSensor::State::FAIL: return "FAIL";
        default: return "RUN_OUT_OF_STATE";
    }
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
