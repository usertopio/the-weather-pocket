// Framework
#include <Arduino.h>

// Header file
// System
#include "system.h"

// Components
DHTSensor dhtSensor(10);
NEO6M gpsSensor(20, 21);
OLEDDisplay oledDisplay(128, 64, 0x3C);
LedMQ2 led(0);

// Define the global state variable
SystemState systemState = SystemState::INIT;

// Variables
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
            // Initialize
            // Monitor
            Serial.begin(115200);
            // Components
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
            
            delay(1000);
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


            break;
        case SystemState::MEASURE_MQ2:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            Serial.print("State"); Serial.println("2");

            // Display


            break;
        case SystemState::MEASURE_NEO6M:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            Serial.print("State"); Serial.println("3");

            // Display


            break;
        case SystemState::PROCESS_DATA:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            Serial.print("State"); Serial.println("4");

            // Display


            break;
        case SystemState::UPLOAD_DATA:
            // WIFI


            // Action
            

            // Read data


            // Serial monitor
            Serial.print("State"); Serial.println("5");

            // Display


            break;
        default:
            Serial.println("Not fit to any state. Code need to be fixed!");
            break;
    }
}


// Serial monitor
void monitor(){
    switch (systemState)
    {
    case SystemState::INIT:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
        Serial.println("=========");
        break;

    case SystemState::MEASURE_BME280:
        switch (dhtSensor.getState())
        {
        case DHTSensor::State::MEASURE_TEMPERATURE:
            Serial.println("=========");
            Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
            Serial.print("Sensor Status: "); Serial.println(static_cast<int>(dhtSensor.getStatus()));
            Serial.print("Sensor State: "); Serial.println(static_cast<int>(dhtSensor.getState()));
            Serial.println("");
            Serial.print("DHT22 Temperature: "); Serial.println(dhtSensor.getTemp());
            Serial.println("=========");
            break;
        case DHTSensor::State::MEASURE_HUMIDITY:
            Serial.println("=========");
            Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
            Serial.print("Sensor Status: "); Serial.println(static_cast<int>(dhtSensor.getStatus()));
            Serial.print("Sensor State: "); Serial.println(static_cast<int>(dhtSensor.getState()));
            Serial.println("");
            Serial.print("DHT22 Humidity: "); Serial.println(dhtSensor.getHumid());
            Serial.println("=========");
            break;
        
        default:
            Serial.println("Error");
            break;
        }

        break;
    
    case SystemState::MEASURE_MQ2:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
        Serial.print("Sensor Status: "); Serial.println("NaN");
        Serial.print("Sensor State: "); Serial.println("NaN");
        Serial.println("");
        Serial.print("MQ2 Smoke: "); Serial.println("NaN");
        Serial.println("=========");
        break;
    
    case SystemState::MEASURE_NEO6M:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
        Serial.print("Sensor Status: "); Serial.println("NaN");
        Serial.print("Sensor State: "); Serial.println("NaN");
        Serial.println("");
        Serial.print("NEO6M Lat: "); Serial.println("NaN");
        Serial.print("NEO6M Lon: "); Serial.println("NaN");
        Serial.println("=========");
        break;

    case SystemState::PROCESS_DATA:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
        Serial.println("");
        Serial.println("Processing data...");
        Serial.println("=========");
        break;

    case SystemState::UPLOAD_DATA:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
        Serial.println("");
        Serial.println("Uploading data...");
        Serial.println("=========");
        break;
    
    default:
        
        break;
    }
}