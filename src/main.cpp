// Libraries
#include <Arduino.h>

// Processing headers
#include "system.h"

void setup() {
    
    delay(1000);
}

void loop() {
    updateSystemState();
    runSystemState();
    delay(1000);
}
