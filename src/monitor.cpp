// Framework
#include <Arduino.h>

// Header files
// Child components
#include "monitor.h"
#include "system.h"

void monitor(){
    switch (systemState)
    {
    case SystemState::INIT:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(systemStateToString(systemState));
        Serial.println("=========");
        break;

    case SystemState::READ_BME280:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(systemStateToString(systemState));
        Serial.print("Sensor Status: "); Serial.println(bme280.statusToStr(bme280.getStatus()));
        Serial.print("Sensor State: "); Serial.println(bme280StateToString(bme280.getState()));
        Serial.println("");
        Serial.print("BME280 Temperature: "); Serial.println(bme280.getTemp());
        Serial.print("BME280 Humidity: "); Serial.println(bme280.getHumid());
        Serial.print("BME280 Raw Pressure: "); Serial.println(bme280.getRawPressure());
        Serial.print("BME280 Pressure: "); Serial.println(bme280.getPressure());
        Serial.print("BME280 Alititude: "); Serial.println(bme280.getAltitude());
        Serial.println("=========");
        break;
    
    case SystemState::READ_MQ2:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(systemStateToString(systemState));
        Serial.print("Sensor Status: "); Serial.println(mq2.statusToStr(mq2.getStatus()));
        Serial.print("Sensor State: "); Serial.println(mq2StateToString(mq2.getState()));
        Serial.println("");
        Serial.print("MQ2 Raw: "); Serial.println(mq2.getRaw());
        Serial.print("MQ2 LPG: "); Serial.println(mq2.getLPG());
        Serial.print("MQ2 CO: "); Serial.println(mq2.getCO());
        Serial.print("MQ2 Smoke: "); Serial.println(mq2.getSmoke());
        Serial.println("=========");
        break;
    
    case SystemState::READ_NEO6M:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(systemStateToString(systemState));
        Serial.print("Sensor Status: "); Serial.println(neo6m.statusToStr(neo6m.getStatus()));
        Serial.print("Sensor State: "); Serial.println(neo6mStateToString(neo6m.getState()));
        Serial.println("");
        // Location
        Serial.println("Location"); 
        Serial.print("NEO6M Latitude: "); Serial.println(neo6m.getLatitude());
        Serial.print("NEO6M Longitude: "); Serial.println(neo6m.getLongitude());
        Serial.print("NEO6M Altitude: "); Serial.println(neo6m.getAltitude());
        Serial.print("NEO6M Speed: "); Serial.println(neo6m.getSpeed());
        // Date and time
        Serial.println("Date and time");
        Serial.print("Date: ");  
        Serial.print(neo6m.getDay()); Serial.print(", ");
        Serial.print(neo6m.getMonth()); Serial.print(", ");
        Serial.println(neo6m.getYear());

        Serial.print("NEO6M Time: ");
        Serial.print(neo6m.getHour()); Serial.print(", ");
        Serial.print(neo6m.getMinute()); Serial.print(", ");
        Serial.println(neo6m.getSecond());

        // Accuracy
        Serial.println("Accuracy"); 
        Serial.print("NEO6M Amount of satellite: "); Serial.println(neo6m.getAmountOfSat());
        Serial.print("NEO6M HDOP: "); Serial.println(neo6m.getHDOP());
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
    
    case SystemState::IDLE:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(systemStateToString(systemState));
        Serial.println("");
        Serial.println("All sensor are off");
        Serial.println("=========");
        break;
    
    default:
        Serial.println("Run out of display state!");
        break;
    }
}