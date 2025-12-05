#ifndef MQ2_H
#define MQ2_H

// Header files
#include "component.h"

class Mq2 : public Component {
public:
    // State
    enum class State {
        INIT,
        READ,
        FAIL
    };

    enum class LpgStatus {
        NORMAL,
        WARNING,
        DANGER
    };

    enum class CoStatus {
        NORMAL,
        WARNING,
        DANGER,
        SEVERE
    };

    enum class SmokeStatus {
        NORMAL,
        WARNING,
        DANGER
    };

    // Constructor
    Mq2(int data_pin);

    //  Initialization
    void begin() override;

    // State
    State getState() const;
    void setState(State newState);
    
    void setLpgStatus(LpgStatus newLpgStatus);
    void setCoStatus(CoStatus newCoStatus);
    void setSmokeStatus(SmokeStatus newSmokeStatus);

    // Read data
    void readRaw();
    void readLPG();
    void readCO();
    void readSmoke();

    // Get status
    LpgStatus getLpgStatus() const;
    CoStatus getCoStatus() const;
    SmokeStatus getSmokeStatus() const;
    
    // Get data
    float getRaw();
    float getLPG();
    float getCO();
    float getSmoke();

private:
    // Pins
    const int DATA_PIN;

    // State
    State state;

    LpgStatus lpgStatus;
    CoStatus coStatus;
    SmokeStatus  smokeStatus;

    // Data
    // My data
    float raw;
    float lpg_ppm;
    float co_ppm;
    float smoke_ppm;

    float ratio;

    float calculatePPM(float ratio, float a, float b);
};

// Status
const char* mq2StatusToString(Mq2::Status status);

const char* mq2LpgStatusToStr(Mq2::LpgStatus lpgStatus);
const char* mq2CoStatusToStr(Mq2::CoStatus coStatus);
const char* mq2SmokeStatusToStr(Mq2::SmokeStatus smokeStatus);

// State
const char* mq2StateToString(Mq2::State state);

#endif