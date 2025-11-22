// Header files
// Child components
#include "bme280.h"

// Constructor
BME280::BME280(int bme_mosi, int bme_miso, int bme_sck, int bme_cs, float sea_level_pressure_hpa) :
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
void BME280::begin(){
    // Libraries
    bme.begin();
    // State
    status = Status::ON;
}

// State
BME280::State BME280::getState() const {
    return state;
}

// Read data
void BME280::readAllData(){
    temp = bme.readTemperature();
    humid = bme.readHumidity();
    pressure = bme.readPressure();
    altitude = bme.readAltitude(SEA_LEVEL_PRESSURE_HPA);
}

void BME280::readTemp(){
    temp = bme.readTemperature();
}

void BME280::readHumid(){
    humid = bme.readHumidity();
}

void BME280::readPressure(){
    pressure = bme.readPressure();
}

void BME280::readAltitude(){
    altitude = bme.readAltitude(SEA_LEVEL_PRESSURE_HPA);
}

// Get data
float BME280::getTemp(){
    return temp;
}

float BME280::getHumid(){
    return humid;
}

float BME280::getPressure(){
    return pressure;
}

float BME280::getAltitude(){
    return altitude;
}
