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
extern OledDisplay oledDisplay;
extern LedMQ2 led;

// State
enum class SystemState {
    INIT,
    READ_DHT,
    MEASURE_MQ2,
    MEASURE_NEO6M,
    PROCESS_DATA,
    UPLOAD_DATA
};

extern SystemState systemState;

// Variables
// Buffer
extern bool isMQ2On;
extern bool isNEO6MOn;
extern bool isWifiConnect;

const char* systemStateToString(SystemState state);

void updateSystemState();
void runSystemState();

// Serial monitor
void monitor();

#endif