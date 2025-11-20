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
DHTSensor dhtSensor(10);
NEO6M gpsSensor(20, 21);
OLEDDisplay oledDisplay(128, 64, 0x3C);
LED led(0);

void setup() {
  Serial.begin(115200);
    delay(1000);
}

void loop() {
    switch (currentState)
    {
        case SystemState::INIT:
            // Initialize all components
            dhtSensor.begin();
            gpsSensor.begin();
            oledDisplay.begin();
            led.begin();

            // Display

            // Next state

            break;
        case SystemState::MEASURE_WEATHER:
            if (dhtSensor.getStatus() == DHTSensor::Status::ON){
                Serial.print("This is called");
            }
            
            break;
        case SystemState::MEASURE_GPS:
            /* code */
            break;
        case SystemState::PROCESS_DATA:
            /* code */
            break;
        case SystemState::UPLOAD_DATA:
            /* code */
            break;
        default:
            Serial.print("Not fit to any state");
            break;
    }
}
