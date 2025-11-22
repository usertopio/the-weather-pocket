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

// State
void DHTSensor::setState(State newState) {
    state = newState;
}

void DHTSensor::readTemp(){
    temp = dht.readTemperature();

    // Update state
    setState(State::MEASURE_TEMPERATURE);
}

void DHTSensor::readHumid(){
    humid = dht.readHumidity();

    // Update state
    setState(State::MEASURE_HUMIDITY);
}

void DHTSensor::readTempAndHumid() {
    // static unsigned long lastRead = 0;
    // if (millis() - lastRead < 2100) return;  // enforce 2.1s interval

    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (!isnan(t)) temp = t;
    if (!isnan(h)) humid = h;

    // lastRead = millis();
}


float DHTSensor::getTemp(){
    return temp;
}

float DHTSensor::getHumid(){
    return humid;
}
