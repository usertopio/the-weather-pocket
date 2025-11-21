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