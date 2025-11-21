// Framework
#include <Arduino.h>

// Header file
// System
#include "system.h"

// Components
DHTSensor dhtSensor(10);
NEO6M gpsSensor(20, 21);
OLEDDisplay oledDisplay(128, 64, 0x3C);
LED led(0);

// Define the global state variable
SystemState systemState = SystemState::INIT;

// Serial monitor
void monitor(float dht_temp, float dht_humid, Sensor::Status component_status, DHTSensor::State component_state){
    switch (systemState)
    {
    case SystemState::INIT:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
        Serial.print("Sensor Status: "); Serial.println(static_cast<int>(component_status));
        Serial.print("Sensor State: "); Serial.println(static_cast<int>(component_state));
        Serial.println("");
        Serial.print("DHT22 Temperature: "); Serial.println(dht_temp);
        Serial.print("DHT22 Humidity: "); Serial.println(dht_humid);
        Serial.println("=========");
        break;

    case SystemState::MEASURE_BME280:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
        Serial.print("Sensor Status: "); Serial.println(static_cast<int>(component_status));
        Serial.print("Sensor State: "); Serial.println(static_cast<int>(component_state));
        Serial.println("");
        Serial.print("DHT22 Temperature: "); Serial.println(dht_temp);
        Serial.print("DHT22 Humidity: "); Serial.println(dht_humid);
        Serial.println("=========");
        break;
    
    case SystemState::MEASURE_MQ2:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
        Serial.print("Sensor Status: "); Serial.println(static_cast<int>(component_status));
        Serial.print("Sensor State: "); Serial.println(static_cast<int>(component_state));
        Serial.println("");
        Serial.print("DHT22 Temperature: "); Serial.println(dht_temp);
        Serial.print("DHT22 Humidity: "); Serial.println(dht_humid);
        Serial.println("=========");
        break;
    
    case SystemState::MEASURE_NEO6M:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
        Serial.print("Sensor Status: "); Serial.println(static_cast<int>(component_status));
        Serial.print("Sensor State: "); Serial.println(static_cast<int>(component_state));
        Serial.println("");
        Serial.print("DHT22 Temperature: "); Serial.println(dht_temp);
        Serial.print("DHT22 Humidity: "); Serial.println(dht_humid);
        Serial.println("=========");
        break;

    case SystemState::PROCESS_DATA:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
        Serial.print("Sensor Status: "); Serial.println(static_cast<int>(component_status));
        Serial.print("Sensor State: "); Serial.println(static_cast<int>(component_state));
        Serial.println("");
        Serial.print("DHT22 Temperature: "); Serial.println(dht_temp);
        Serial.print("DHT22 Humidity: "); Serial.println(dht_humid);
        Serial.println("=========");
        break;

    case SystemState::UPLOAD_DATA:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
        Serial.print("Sensor Status: "); Serial.println(static_cast<int>(component_status));
        Serial.print("Sensor State: "); Serial.println(static_cast<int>(component_state));
        Serial.println("");
        Serial.print("DHT22 Temperature: "); Serial.println(dht_temp);
        Serial.print("DHT22 Humidity: "); Serial.println(dht_humid);
        Serial.println("=========");
        break;
    
    default:
        
        break;
    }

    Serial.println("=========");
    Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
    Serial.print("Sensor Status: "); Serial.println(static_cast<int>(component_status));
    Serial.print("Sensor State: "); Serial.println(static_cast<int>(component_state));
    Serial.println("");
    Serial.print("DHT22 Temperature: "); Serial.println(dht_temp);
    Serial.print("DHT22 Humidity: "); Serial.println(dht_humid);
    Serial.println("=========");
}