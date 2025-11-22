#ifndef DHT22_H
#define DHT22_H

// Libraries
#include <DHT.h>

// Header files
#include "component.h"

class DhtSensor : public Component {
public:
    // State
    enum class State {
        INIT,
        READ,
        FAIL
    };

    // Constructor
    DhtSensor(int dht_pin);

    //  Initialization
    void begin() override;

    // State
    State getState() const;
    void setState(State newState); 

    // Read data
    void readTemp();
    void readHumid();
    void readTempAndHumid();

    // Get data
    float getTemp();
    float getHumid();

private:
    // Pins
    const int DHT_PIN;

    // State
    State state;

    // Data
    // Libraries
    DHT dht;
    // My data
    float temp;
    float humid;
};

#endif