// Libraries
#include <Arduino.h>

// Processing headers
#include "system.h"

void setup() {
    // Monitor
    Serial.begin(115200);
    delay(2000);
}

void loop() {
    updateSystemState();
    delay(2000);
    runSystemState();
    delay(1000);
}
