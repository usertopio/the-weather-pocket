// Framework
#include <Arduino.h>

// Header files
// Processing headers
#include "system.h"

// Component instances
// Sensors
// BME280 bme280(6, 5, 4, 7, 1010);
DHTSensor dhtSensor(10);
NEO6M gpsSensor(20, 21);
// Display
OledDisplay oledDisplay(128, 64, 0x3C);
// Leds
LedMQ2 ledMq2(0);
LedNeo6m ledNeo6m(1);
// Buttons
ButtonOledDisplay buttonOledDisplay(2);
ButtonWifi buttonWifi(3);

// State
SystemState systemState = SystemState::INIT;

// Data
// Buffer
bool isMQ2On = true;
bool isNEO6MOn = true;
bool isWifiConnect = true;

// State
void updateSystemState(){
    switch (systemState)
    {
    case SystemState::INIT:
        if (dhtSensor.getStatus() == DHTSensor::Status::ON){
            systemState = SystemState::READ_DHT;
        } else if (isMQ2On){
            systemState = SystemState::READ_MQ2;
        } else if (isNEO6MOn){
            systemState = SystemState::READ_NEO6M;
        } else {
            systemState = SystemState::PROCESS_DATA;
        }
        break;
    // // #16 #3
    // case SystemState::READ_BME280:
    //     if (isMQ2On){
    //         systemState = SystemState::READ_MQ2;
    //     }
    //     else if (isNEO6MOn){
    //         systemState = SystemState::READ_NEO6M;
    //     }
    //     else{
    //         systemState = SystemState::PROCESS_DATA;
    //     }
    //     break;
    
    case SystemState::READ_DHT:
        if (isMQ2On){
            systemState = SystemState::READ_MQ2;
        }
        else if (isNEO6MOn){
            systemState = SystemState::READ_NEO6M;
        }
        else{
            systemState = SystemState::PROCESS_DATA;
        }
        break;
    // #13
    case SystemState::READ_MQ2:
        if (isNEO6MOn){
            systemState = SystemState::READ_NEO6M;
        }
        else{
            systemState = SystemState::PROCESS_DATA;
        }
        break;
    // #14
    case SystemState::READ_NEO6M:
        systemState = SystemState::PROCESS_DATA;
        break;

    case SystemState::PROCESS_DATA:
        if (!isWifiConnect){
            systemState = SystemState::READ_DHT;
        } else{
            systemState = SystemState::UPLOAD_DATA;
        }
        break;

    case SystemState::UPLOAD_DATA:
        systemState = SystemState::READ_DHT;
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
            // bme280.begin();
            dhtSensor.begin();
            gpsSensor.begin();
            oledDisplay.begin();
            led.begin();
            // WIFI


            // Action
            

            // Read data

            
            // Serial monitor
            monitor();

            // Display
            
            // delay(1000);
            break;
        case SystemState::READ_DHT:
            // WIFI


            // Action

            
            // Read data
            dhtSensor.readTempAndHumid();
            // Serial monitor
            monitor();
            
            // Display


            break;
        case SystemState::READ_MQ2:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            monitor();

            // Display


            break;
        case SystemState::READ_NEO6M:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            monitor();

            // Display


            break;
        case SystemState::PROCESS_DATA:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            monitor();

            // Display


            break;
        case SystemState::UPLOAD_DATA:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            monitor();

            // Display


            break;
        default:
            Serial.println("Run out of state. Plese fix the code!");
            break;
    }
}

const char* systemStateToString(SystemState state) {
    switch (state) {
        case SystemState::INIT: return "INIT";
        case SystemState::READ_DHT: return "READ_DHT";
        case SystemState::READ_MQ2: return "READ_MQ2";
        case SystemState::READ_NEO6M: return "READ_NEO6M";
        case SystemState::PROCESS_DATA: return "PROCESS_DATA";
        case SystemState::UPLOAD_DATA: return "UPLOAD_DATA";
        default: return "RUN_OUT_OF_STATE";
    }
}

// Serial monitor
void monitor(){
    switch (systemState)
    {
    case SystemState::INIT:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(systemStateToString(systemState));
        Serial.println("=========");
        break;

    case SystemState::READ_DHT:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(systemStateToString(systemState));
        Serial.print("Sensor Status: "); Serial.println(static_cast<int>(dhtSensor.getStatus()));
        Serial.print("Sensor State: "); Serial.println(static_cast<int>(dhtSensor.getState()));
        Serial.println("");
        Serial.print("DHT22 Temperature: "); Serial.println(dhtSensor.getTemp());
        Serial.print("DHT22 Humidity: "); Serial.println(dhtSensor.getHumid());
        Serial.println("=========");
        break;
    
    case SystemState::READ_MQ2:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(systemStateToString(systemState));
        Serial.print("Sensor Status: "); Serial.println("NaN");
        Serial.print("Sensor State: "); Serial.println("NaN");
        Serial.println("");
        Serial.print("MQ2 Smoke: "); Serial.println("NaN");
        Serial.println("=========");
        break;
    
    case SystemState::READ_NEO6M:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(systemStateToString(systemState));
        Serial.print("Sensor Status: "); Serial.println("NaN");
        Serial.print("Sensor State: "); Serial.println("NaN");
        Serial.println("");
        Serial.print("NEO6M Lat: "); Serial.println("NaN");
        Serial.print("NEO6M Lon: "); Serial.println("NaN");
        Serial.println("=========");
        break;

    case SystemState::PROCESS_DATA:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(systemStateToString(systemState));
        Serial.println("");
        Serial.println("Processing data...");
        Serial.println("=========");
        break;

    case SystemState::UPLOAD_DATA:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(systemStateToString(systemState));
        Serial.println("");
        Serial.println("Uploading data...");
        Serial.println("=========");
        break;
    
    default:
        
        break;
    }
}