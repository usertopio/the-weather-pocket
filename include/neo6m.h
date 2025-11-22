#ifndef NEO6M_H
#define NEO6M_H

// Libraries
#include <HardwareSerial.h>
#include <TinyGPS++.h>

// Header files
#include "component.h"

class NEO6M : public Component {
public:
    // State
    enum class State {
        INIT,
        WAIT_FOR_FIX,
        GOT_FIX
    };

    // Constructor
    NEO6M(int neo_rx, int neo_tx);

    //  Initialization
    void begin() override;

    // State
    State getState() const;
    void setState(State newState); 

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
};

#endif