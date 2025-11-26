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
    runSystemState();
    delay(500);
    updateSystemState();
    delay(500);
}
