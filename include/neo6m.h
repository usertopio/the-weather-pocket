#ifndef NEO6M_H
#define NEO6M_H

// Libraries
#include <HardwareSerial.h>
#include <TinyGPS++.h>

// Header files
#include "component.h"

class Neo6m : public Component {
public:
    // State
    enum class State {
        INIT,
        WAIT_FOR_FIX,
        GOT_FIX
    };

    // Constructor
    Neo6m(int neo_rx, int neo_tx);

    //  Initialization
    void begin() override;

    // State
    State getState() const;
    void setState(State newState);

    // Read data
    void readData();

    // Get data
    float getLatitude();
    float getLongitude();
    float getAltitude();
    float getDate();
    float getTime();
    float getSpeed();
    float getAmountOfSat();
    float getHDOP();

private:
    // Pins
    const int NEO_RX;
    const int NEO_TX;

    // State
    State state;

    // Data
    // Libraries
    TinyGPSPlus gps;
    HardwareSerial &gpsSerial = Serial1;
    // My data
    float latitude;
    float longitude;
    float altitude;
    float date;
    float time;
    float speed;
    float amount_of_satellite;
    float hdop;
};

// Status
const char* neo6mStatusToString(Neo6m::Status status);

// State
const char* neo6mStateToString(Neo6m::State state);

#endif