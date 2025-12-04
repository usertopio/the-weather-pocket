#ifndef SYSTEM_H
#define SYSTEM_H

// Header files
// Parent components
#include "component.h"
// Child components
// Sensors
#include "bme280.h"
#include "mq2.h"
#include "neo6m.h"
// Display
#include "oledDisplay.h"
// Leds
#include "ledMq2.h"
#include "ledNeo6m.h"
// Buttons
#include "buttonNext.h"
#include "buttonConfirm.h"


// Component instances
extern Bme280 bme280;
extern Mq2 mq2;
extern Neo6m neo6m;
extern OledDisplay oledDisplay;
extern LedMq2 ledMq2;
extern LedNeo6m ledNeo6m;

// State
enum class SystemState {
    INIT,
    READ_BME280,
    READ_MQ2,
    READ_NEO6M,
    PROCESS_DATA,
    UPLOAD_DATA
};

extern SystemState systemState;

// State
const char* systemStateToString(SystemState state);
void updateSystemState();
void runSystemState();

// Serial monitor
void monitor();

// Data
// Buffer
extern bool isWifiConnect;


#endif