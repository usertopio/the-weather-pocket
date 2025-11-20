#ifndef NEO6M_H
#define NEO6M_H

// Libraries
#include <HardwareSerial.h>
#include <TinyGPS++.h>

// Header files
#include "sensor.h"

class NEO6M : public Sensor {
public:
    // ===== Types & Enums =====
    enum class State {
        INIT,
        ACQUIRE_SIGNAL,
        READ_LOCATION,
        READ_DATE,
        READ_TIME
    };

    // ===== Constructor & Destructor =====
    NEO6M(int neo_rx, int neo_tx);

    // ===== Public Methods =====
    void begin() override;
    State getState() const;

private:
    // ===== Pin Configuration =====
    const int NEO_RX;
    const int NEO_TX;

    // ===== State Variables =====
    State state;

    // ===== Sensor Data =====
    TinyGPSPlus gps;
};

#endif