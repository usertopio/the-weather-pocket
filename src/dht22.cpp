// Header files
#include "dht22.h"

// Sensor Data
float temp = 0.0;
float humid = 0.0;

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

// State
void DHTSensor::setState(State newState) {
    state = newState;
}

float DHTSensor::readTemp(){
    temp = dht.readTemperature();

    // Update state
    setState(State::MEASURE_TEMPERATURE);
    

    return temp;
}

float DHTSensor::readHumid(){
    humid = dht.readHumidity();

    // Update state
    setState(State::MEASURE_HUMIDITY);

    return humid;
}

float DHTSensor::getTemp(){
    return temp;
}

float DHTSensor::getHumid(){
    return humid;
}
