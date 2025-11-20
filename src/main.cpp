// Libraries
#include <Arduino.h>

// Component headers
#include "bme280.h"
#include "dht22.h"
#include "neo6m.h"
#include "oledDisplay.h"
#include "led.h"

// Processing headers
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
    switch (systemState)
    {
        case SystemState::INIT:
            // Initialize all components
            dhtSensor.begin();
            gpsSensor.begin();
            oledDisplay.begin();
            led.begin();
            // WIFI


            // Action
            

            // DHT22


            // Display


            // Next state
            systemState = SystemState::MEASURE_BME280;
            break;
        case SystemState::MEASURE_BME280:
            // WIFI


            // Action


            // DHT22

            if (dhtSensor.getStatus() == DHTSensor::Status::ON)
            {
                // Measure
                dhtSensor.readTemp();
                dhtSensor.setState();
                
                dhtSensor.readHumid();

                // Serial monitor
                // Data
                Serial.println("========="); 
                Serial.print("DHT22 Temperature: "); Serial.println(dhtSensor.getTemp());
                Serial.print("DHT22 Humidity: "); Serial.println(dhtSensor.getHumid());
                // System
                Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
                Serial.print("Sensor Status: "); Serial.println();
                Serial.println("========="); 
            }

            // Display


            // Next state
            systemState = SystemState::MEASURE_MQ2;
            break;
        case SystemState::MEASURE_MQ2:
            // WIFI


            // Action
            

            // DHT22


            // Display


            // Next state
            systemState = SystemState::MEASURE_NEO6M;
            break;
        case SystemState::MEASURE_NEO6M:
            // WIFI


            // Action
            

            // DHT22


            // Display


            // Next state
            systemState = SystemState::PROCESS_DATA;
            break;
        case SystemState::PROCESS_DATA:
            // WIFI


            // Action
            

            // DHT22


            // Display


            // Next state
            systemState = SystemState::UPLOAD_DATA;
            break;
        case SystemState::UPLOAD_DATA:
            // WIFI


            // Action
            

            // DHT22


            // Display


            // Next state
            systemState = SystemState::MEASURE_BME280;
            break;
        default:
            Serial.println("Not fit to any state. Code need to be fixed!");
            break;
    }
}
