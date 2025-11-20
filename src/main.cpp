#include <Arduino.h>

// Component headers
#include "bme280.h"
#include "dht22.h"
#include "neo6m.h"
#include "oledDisplay.h"
#include "led.h"

#include "system.h"

// ===== Component Instances =====
// BME280 bme(BME_MOSI, BME_MISO, BME_SCK, BME_CS);
DHTSensor dht(10);
NEO6M gps(20, 21);
OLEDDisplay oled(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_RESET);
LED led(0);

void setup() {
  Serial.begin(115200);
    delay(1000);
}

void loop() {
    switch (currentState)
    {
        case INIT:
            /* code */
            break;
        case MEASURE:
            /* code */
            break;
        case DATA:
            /* code */
            break;
        default:
            break;
    }
}
