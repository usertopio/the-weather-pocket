// Libraries
#include <Arduino.h>

// Processing headers
#include "system.h"

void setup() {
    Serial.begin(115200);
    delay(1000);
}

void loop() {
    updateSystemState();
    runSystemState();
    delay(1000);
}
