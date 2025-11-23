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
    void read();

    void readLocation();
    void readDateAndTime();
    void readAccuracy();

    // Get data
    float getLatitude();
    float getLongitude();
    float getAltitude();
    float getSpeed();
    
    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();
    int getSecond();

    int getAmountOfSat();
    int getHDOP();

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
    struct Location {
        float latitude;
        float longitude;
        float altitude;
        float speed;
    };

    struct DateAndTime {
        int year;
        int month;
        int day;

        int hour;
        int minute;
        int second;
    };
    
    struct Accuracy {
        int amount_of_satellite;
        int hdop;
    };

protected:
    Location location;
    DateAndTime dateAndTime;
    Accuracy accuracy;
};

// Status
const char* neo6mStatusToString(Neo6m::Status status);

// State
const char* neo6mStateToString(Neo6m::State state);

#endif