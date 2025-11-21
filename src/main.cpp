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

// Experiment buffer
bool isMQ2On = true;
bool isNEO6MOn = true;
bool isWifiConnect = true;

// State
void updateSystemState(){
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
        systemState = SystemState::INIT;
        break;
    }
}

void runSystemState(){
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

            
            // Serial monitor
            Serial.print("State"); Serial.println("0");

            // Display
            

            // Next state
            
            break;
        case SystemState::MEASURE_BME280:
            // WIFI


            // Action

            
            // Read data
            dhtSensor.readTemp();
            // Serial monitor
            monitor();

            dhtSensor.readHumid();
            // Serial monitor
            monitor();
            
            // Display


            // Next state
            
            break;
        case SystemState::MEASURE_MQ2:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            Serial.print("State"); Serial.println("2");

            // Display


            // Next state
            
            break;
        case SystemState::MEASURE_NEO6M:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            Serial.print("State"); Serial.println("3");

            // Display


            // Next state
            
            break;
        case SystemState::PROCESS_DATA:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            Serial.print("State"); Serial.println("4");

            // Display


            // Next state
            
            break;
        case SystemState::UPLOAD_DATA:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            Serial.print("State"); Serial.println("5");

            // Display


            // Next state
            
            break;
        default:
            Serial.println("Not fit to any state. Code need to be fixed!");
            break;
    }
}

void setup() {
    Serial.begin(115200);
    delay(1000);
}

void loop() {
    updateSystemState();
    runSystemState();
    delay(1000);
}
