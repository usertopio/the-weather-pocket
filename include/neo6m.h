#ifndef NEO6M_H
#define NEO6M_H

// Libraries
#include <HardwareSerial.h>
#include <TinyGPS++.h>

// Header files
#include "component.h"

class Neo6m : public Component {
public:

    // State machine
    enum class State {
        INIT,
        WAIT_FOR_FIX,
        GOT_FIX
    };

    // Constructor
    Neo6m(int neo_rx, int neo_tx);

    // Initialization
    void begin() override;

    // State
    State getState() const;
    void setState(State newState);

    // Read data from GPS
    void read();
    void readLocation();
    void readDateAndTime();
    void readAccuracy();

    // Get data
    float getLatitude();
    float getLongitude();
    float getAltitude();
    float getSpeed();
    float getCourse();

    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();
    int getSecond();

    int getAmountOfSat();
    float getHDOP();

private:
    // Pins
    const int NEO_RX;
    const int NEO_TX;

    // State
    State state;

    // GPS Library
    TinyGPSPlus gps;
    HardwareSerial& gpsSerial = Serial1;

    // My data structures
    struct Location {
        float latitude = 0;
        float longitude = 0;
        float altitude = 0;
        float speed = 0;
        float course = 0;
    };

    struct DateAndTime {
        int year = 0;
        int month = 0;
        int day = 0;
        int hour = 0;
        int minute = 0;
        int second = 0;
    };

    struct Accuracy {
        int amount_of_satellite = 0;
        float hdop = 0;
    };

protected:
    Location location;
    DateAndTime dateAndTime;
    Accuracy accuracy;
};

// State
const char* neo6mStateToString(Neo6m::State state);

#endif
