// Framework
#include <Arduino.h>

// Header files
// Processing headers
#include "system.h"

#include "monitor.h"

// Component instances
// Sensors
Bme280 bme280(6, 5, 4, 7, 1013.25);
Mq2 mq2(2);
Neo6m neo6m(20, 21);
// Display
OledDisplay oledDisplay(8, 9, 128, 64, 0x3C);
// Leds
LedMq2 ledMq2(0);
LedNeo6m ledNeo6m(1);

// State
SystemState systemState = SystemState::INIT;

// Data
// Buffer
bool isWifiConnect = true;

// State
void updateSystemState(){
    switch (systemState)
    {
    case SystemState::INIT:
        if (bme280.getStatus() == Bme280::Status::ON){
            systemState = SystemState::READ_BME280;
        } else if (mq2.getStatus() == Mq2::Status::ON){
            systemState = SystemState::READ_MQ2;
        } else if (neo6m.getStatus() == Neo6m::Status::ON){
            systemState = SystemState::READ_NEO6M;
        } else {
            systemState = SystemState::IDLE;
        }
        break;
    // // #16 #3
    case SystemState::READ_BME280:
        if (mq2.getStatus() == Mq2::Status::ON){
            systemState = SystemState::READ_MQ2;
        } else if (neo6m.getStatus() == Neo6m::Status::ON){
            systemState = SystemState::READ_NEO6M;
        } else {
            systemState = SystemState::PROCESS_DATA;
        }
        break;
    // #13
    case SystemState::READ_MQ2:
        if (neo6m.getStatus() == Neo6m::Status::ON){
            systemState = SystemState::READ_NEO6M;
        } else if (true){
            systemState = SystemState::PROCESS_DATA;
        } else if (true){
            systemState = SystemState::UPLOAD_DATA;
        }
        break;
    // #14
    case SystemState::READ_NEO6M:
        systemState = SystemState::PROCESS_DATA;
        break;

    case SystemState::PROCESS_DATA:
        systemState = SystemState::UPLOAD_DATA;
        break;

    case SystemState::UPLOAD_DATA:
        // systemState = SystemState::READ_BME280;
        if (bme280.getStatus() == Bme280::Status::ON){
            systemState = SystemState::READ_BME280;
        } else if (mq2.getStatus() == Mq2::Status::ON){
            systemState = SystemState::READ_MQ2;
        } else if (neo6m.getStatus() == Neo6m::Status::ON){
            systemState = SystemState::READ_NEO6M;
        } else {
            systemState = SystemState::IDLE;
        }
        break;

    case SystemState::IDLE:
        // systemState = SystemState::READ_BME280;
        if (bme280.getStatus() == Bme280::Status::ON){
            systemState = SystemState::READ_BME280;
        } else if (mq2.getStatus() == Mq2::Status::ON){
            systemState = SystemState::READ_MQ2;
        } else if (neo6m.getStatus() == Neo6m::Status::ON){
            systemState = SystemState::READ_NEO6M;
        } else {
            systemState = SystemState::IDLE;
        }
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
            // Initialize the components
            // Sensors
            bme280.begin();
            // delay(1000);
            neo6m.begin();
            // Display
            oledDisplay.begin();
            // Leds
            ledMq2.begin();
            ledNeo6m.begin();
            // Buttons
            buttonNext.begin();
            buttonConfirm.begin();
            // WIFI


            // Action
            

            // Read data

            
            // Serial monitor
            monitor();

            // Display
            oledDisplay.updateDisplay();
            
            break;
        case SystemState::READ_BME280:
            // WIFI


            // Action
            
            
            // Read data
            bme280.read();
            // delay(2000);
            // Serial monitor
            monitor();
            
            // Display
            oledDisplay.updateDisplay();

            break;
        case SystemState::READ_MQ2:
            // WIFI


            // Action
            

            // Read data
            mq2.readLPG();
            mq2.readCO();
            mq2.readSmoke();

            // Serial monitor
            monitor();

            // Display
            oledDisplay.updateDisplay();

            break;
        case SystemState::READ_NEO6M:
            // WIFI


            // Action
            

            // Read data
            neo6m.read();

            // Serial monitor
            monitor();

            // Display
            oledDisplay.updateDisplay();

            break;
        case SystemState::PROCESS_DATA:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            monitor();

            // Display
            oledDisplay.updateDisplay();

            break;
        case SystemState::UPLOAD_DATA:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            monitor();

            // Display
            oledDisplay.updateDisplay();

            break;

        case SystemState::IDLE:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            monitor();

            // Display
            oledDisplay.updateDisplay();

            break;
            
        default:
            Serial.println("Run out of state. Plese fix the code!");
            break;
    }
}

const char* systemStateToString(SystemState state) {
    switch (state) {
        case SystemState::INIT: return "INIT";
        case SystemState::READ_BME280: return "READ_BME280";
        case SystemState::READ_MQ2: return "READ_MQ2";
        case SystemState::READ_NEO6M: return "READ_NEO6M";
        case SystemState::PROCESS_DATA: return "PROCESS_DATA";
        case SystemState::UPLOAD_DATA: return "UPLOAD_DATA";
        default: return "RUN_OUT_OF_STATE";
    }
}