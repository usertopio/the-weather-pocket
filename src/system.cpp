// Framework
#include <Arduino.h>

// Header file
#include "system.h"

// Define the global state variable
SystemState currentState = SystemState::INIT;

// Serial monitor
void monitor(float dht_temp, float dht_humid, int component_status, int component_state){
    // System
    Serial.println("========="); 
    Serial.print("System State: "); Serial.println(static_cast<int>(systemState));
    Serial.print("Sensor Status: "); Serial.println(static_cast<int>(component_status));
    Serial.print("Sensor State: "); Serial.println(static_cast<int>(component_state));
    // Sensor
    Serial.println("");
    Serial.print("DHT22 Temperature: "); Serial.println(dht_temp);
    Serial.print("DHT22 Humidity: "); Serial.println(dht_humid);
    Serial.println("========="); 
}