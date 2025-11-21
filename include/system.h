#ifndef SYSTEM_H
#define SYSTEM_H

// Header files
// Components
#include "sensor.h"

#include "bme280.h"
#include "dht22.h"
#include "neo6m.h"
#include "oledDisplay.h"
#include "ledMq2.h"
#include "ledNeo6m.h"

// Components
extern DHTSensor dhtSensor;
extern NEO6M gpsSensor;
extern OLEDDisplay oledDisplay;
extern LedMQ2 led;

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

// Variables
// Buffer
bool isMQ2On;
bool isNEO6MOn;
bool isWifiConnect;

void updateSystemState();
void runSystemState();

// Serial monitor
void monitor();

#endif