// Framework
#include <Arduino.h>

// Header files
// Processing headers
#include "system.h"

// Component instances
// Sensors
// Bme280 bme280(6, 5, 4, 7, 1010);
DhtSensor dhtSensor(10);
Mq2 mq2(5); // GPIO5 for production
Neo6m neo6m(20, 21);
// Display
OledDisplay oledDisplay(128, 64, 0x3C);
// Leds
LedMq2 ledMq2(0);
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
        if (dhtSensor.getStatus() == DhtSensor::Status::ON){
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
            neo6m.begin();
            // Display
            oledDisplay.begin();
            // Leds
            ledMq2.begin();
            ledNeo6m.begin();
            // Buttons
            buttonOledDisplay.begin();
            buttonWifi.begin();
            // WIFI


            // Action
            

            // Read data

            
            // Serial monitor
            monitor();

            // Display
            
            break;
        case SystemState::READ_DHT:
            // WIFI


            // Action

            
            // Read data
            dhtSensor.read();
            // Serial monitor
            monitor();
            
            // Display


            break;
        case SystemState::READ_MQ2:
            // WIFI


            // Action
            

            // Read data
            mq2.getGas();

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

    // case SystemState::READ_BME280:
    //     Serial.println("=========");
    //     Serial.print("System State: "); Serial.println(systemStateToString(systemState));
    //     Serial.print("Sensor Status: "); Serial.println(bme280StatusToString(bme280.getStatus()));
    //     Serial.print("Sensor State: "); Serial.println(bme280StateToString(bme280.getState()));
    //     Serial.println("");
    //     Serial.print("BME280 Temperature: "); Serial.println(bme280.getTemp());
    //     Serial.print("BME280 Humidity: "); Serial.println(bme280.getHumid());
    //     Serial.print("BME280 Pressure: "); Serial.println(bme280.getPressure());
    //     Serial.print("BME280 Alititude: "); Serial.println(bme280.getAltitude());
    //     Serial.println("=========");
    //     break;

    case SystemState::READ_DHT:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(systemStateToString(systemState));
        Serial.print("Sensor Status: "); Serial.println(dht22StatusToString(dhtSensor.getStatus()));
        Serial.print("Sensor State: "); Serial.println(dht22StateToString(dhtSensor.getState()));
        Serial.println("");
        Serial.print("DHT22 Temperature: "); Serial.println(dhtSensor.getTemp());
        Serial.print("DHT22 Humidity: "); Serial.println(dhtSensor.getHumid());
        Serial.println("=========");
        break;
    
    case SystemState::READ_MQ2:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(systemStateToString(systemState));
        Serial.print("Sensor Status: "); Serial.println(mq2StatusToString(mq2.getStatus()));
        Serial.print("Sensor State: "); Serial.println(mq2StateToString(mq2.getState()));
        Serial.println("");
        Serial.print("MQ2 Gas: "); Serial.println(mq2.getGas());
        Serial.println("=========");
        break;
    
    case SystemState::READ_NEO6M:
        Serial.println("=========");
        Serial.print("System State: "); Serial.println(systemStateToString(systemState));
        Serial.print("Sensor Status: "); Serial.println(neo6mStatusToString(neo6m.getStatus()));
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
    
    default:
        
        break;
    }
}