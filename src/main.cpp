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

struct weatherSensorState {
    
};



bool isDHT22(){
    return dhtSensor.getStatus() == DHTSensor::Status::ON;
}

bool isBME280(){
    return true;
}

bool isMQ2(){
    return true;
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

            // Display

            // Next state
            systemState = SystemState::MEASURE_WEATHER;

            break;
        case SystemState::MEASURE_WEATHER:
            if (isDHT22() && isMQ2())
            {
                // DHT22
                dhtSensor.getTemp();
                dhtSensor.getHumid();

            }
            else if (!isDHT22() && isMQ2())
            {
                /* code */
            }
            else if (isDHT22() && !isMQ2())
            {
                // DHT22
                dhtSensor.getTemp();
                dhtSensor.getHumid();
            }
            else if (!isDHT22() && !isMQ2())
            {

            }

            // Display

            // Next state
            systemState = SystemState::MEASURE_GPS;
            
        case SystemState::MEASURE_GPS:
            /* code */
            break;

            // Display

            // Next state
            systemState = SystemState::PROCESS_DATA;
        case SystemState::PROCESS_DATA:
            /* code */
            break;

            // Display

            // Next state
            systemState = SystemState::UPLOAD_DATA;
        case SystemState::UPLOAD_DATA:
            /* code */
            break;

            // Display

            // Next state
            systemState = SystemState::MEASURE_WEATHER;
        default:
            Serial.print("Not fit to any state");
            break;
    }
}
