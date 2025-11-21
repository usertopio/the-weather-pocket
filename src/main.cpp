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

// Experiment buffer
bool isMQ2On = true;
bool isNEO6MOn = true;
bool isWifiConnect = true;

// State
SystemState updateSystemState(){
    switch (systemState)
    {
    case SystemState::INIT:
        if (dhtSensor.getStatus() == DHTSensor::Status::ON){
            systemState = SystemState::MEASURE_BME280;
        } else if (isMQ2On){
            systemState = SystemState::MEASURE_MQ2;
        } else if (isNEO6MOn){
            systemState = SystemState::MEASURE_NEO6M;
        } else {
            systemState = SystemState::PROCESS_DATA;
        }
        break;

    case SystemState::MEASURE_BME280:
        if (isMQ2On){
            systemState = SystemState::MEASURE_MQ2;
        }
        else if (isNEO6MOn){
            systemState = SystemState::MEASURE_NEO6M;
        }
        else{
            systemState = SystemState::PROCESS_DATA;
        }
        
        break;
    
    case SystemState::MEASURE_MQ2:
        if (isNEO6MOn){
            systemState = SystemState::MEASURE_NEO6M;
        }
        else{
            systemState = SystemState::PROCESS_DATA;
        }
        
        break;
    
    case SystemState::MEASURE_NEO6M:
        systemState = SystemState::PROCESS_DATA;

        break;

    case SystemState::PROCESS_DATA:
        if (!isWifiConnect){
            systemState = SystemState::MEASURE_BME280;
        } else{
            systemState = SystemState::UPLOAD_DATA;
        }
        
        break;

    case SystemState::UPLOAD_DATA:
        systemState = SystemState::MEASURE_BME280;
        break;
    
    default:
        break;
    }
}

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
            

            // Read data


            // Display


            // Next state
            updateSystemState();
            break;
        case SystemState::MEASURE_BME280:
            // WIFI


            // Action

            
            // Read data
            dhtSensor.readTemp();
            dhtSensor.readHumid();

            // Serial monitor
            monitor(dhtSensor.getTemp(), dhtSensor.getHumid(), dhtSensor.getStatus(), dhtSensor.getState());
            
            // Display


            // Next state
            updateSystemState();
            break;
        case SystemState::MEASURE_MQ2:
            // WIFI


            // Action
            

            // Read data


            // Display


            // Next state
            updateSystemState();
            break;
        case SystemState::MEASURE_NEO6M:
            // WIFI


            // Action
            

            // Read data


            // Display


            // Next state
            updateSystemState();
            break;
        case SystemState::PROCESS_DATA:
            // WIFI


            // Action
            

            // Read data


            // Display


            // Next state
            updateSystemState();
            break;
        case SystemState::UPLOAD_DATA:
            // WIFI


            // Action
            

            // Read data


            // Display


            // Next state
            updateSystemState();
            break;
        default:
            Serial.println("Not fit to any state. Code need to be fixed!");
            break;
    }
}
