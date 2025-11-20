#ifndef NEO6M_H
#define NEO6M_H

// Libraries
#include <HardwareSerial.h>
#include <TinyGPS++.h>

// Header files
#include "sensor.h"

class NEO6M : public Sensor {
    // Constructor
    public:
        // Methods
        NEO6M(HardwareSerial &serial);

    // Initialization
    public:
        // Methods
        void begin() override;

    // Pins
    private:
        // Variables
        HardwareSerial &gpsSerial;

    // State
    protected:
        // Variables
        enum class State {
            INIT,
            NO_FIX,
            FIX
        };
  
        State state;

    public:
        // Methods
        State getState() const;

    // Data
    private:
        // Variables
        // Library constants
        TinyGPSPlus gps;
};

#endif