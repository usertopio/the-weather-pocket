#ifndef SYSTEM_H
#define SYSTEM_H

// Header files
// Components
#include "sensor.h"

#include "bme280.h"
#include "dht22.h"
#include "neo6m.h"
#include "oledDisplay.h"
#include "led.h"

// Components
extern DHTSensor dhtSensor;
extern NEO6M gpsSensor;
extern OLEDDisplay oledDisplay;
extern LED led;

// State
enum class SystemState {
    INIT,
    MEASURE_BME280,
    MEASURE_MQ2,
    MEASURE_NEO6M,
    PROCESS_DATA,
    UPLOAD_DATA
};

extern SystemState systemState;

// Serial monitor
void monitor(float dht_temp, float dht_humid, Sensor::Status component_status, DHTSensor::State component_state);

#endif