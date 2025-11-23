// Header files
// Child components
#include "bme280.h"

// Constructor
Bme280::Bme280(int bme_mosi, int bme_miso, int bme_sck, int bme_cs, float sea_level_pressure_hpa) :
    // Pins
    BME_MOSI(bme_mosi),
    BME_MISO(bme_miso),
    BME_SCK(bme_sck),
    BME_CS(bme_cs),

    // State
    state(State::INIT),

    // Library
    bme(bme_cs, bme_mosi, bme_miso, bme_sck),

    // Data
    SEA_LEVEL_PRESSURE_HPA(sea_level_pressure_hpa)
{}

// Initialization
void Bme280::begin(){
    // Libraries
    bme.begin();
    // State
    status = Status::ON;
}

// Status
const char* bme280StatusToString(Bme280::Status status) {
    switch (status) {
        case Bme280::Status::ON:  return "ON";
        case Bme280::Status::OFF: return "OFF";
        default: return "UNKNOWN";
    }
}

// State
Bme280::State Bme280::getState() const {
    return state;
}

void Bme280::setState(State newState) {
    state = newState;
}

const char* bme280StateToString(Bme280::State state) {
    switch (state) {
        case Bme280::State::INIT: return "INIT";
        case Bme280::State::READ: return "READ";
        case Bme280::State::FAIL: return "FAIL";
        default: return "RUN_OUT_OF_STATE";
    }
}

// Read data
void Bme280::readAllData(){
    temp = bme.readTemperature();
    humid = bme.readHumidity();
    pressure = bme.readPressure();
    altitude = bme.readAltitude(SEA_LEVEL_PRESSURE_HPA);

    // Update state
    setState(State::READ);
}

void Bme280::readTemp(){
    temp = bme.readTemperature();

    // Update state
    setState(State::READ);
}

void Bme280::readHumid(){
    humid = bme.readHumidity();

    // Update state
    setState(State::READ);
}

void Bme280::readPressure(){
    pressure = bme.readPressure();

    // Update state
    setState(State::READ);
}

void Bme280::readAltitude(){
    altitude = bme.readAltitude(SEA_LEVEL_PRESSURE_HPA);

    // Update state
    setState(State::READ);
}

// Get data
float Bme280::getTemp(){
    return temp;
}

float Bme280::getHumid(){
    return humid;
}

float Bme280::getPressure(){
    return pressure;
}

float Bme280::getAltitude(){
    return altitude;
}
