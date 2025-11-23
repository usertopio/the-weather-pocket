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

    // Constructor
    Mq2(int data_pin);

    //  Initialization
    void begin() override;

    // State
    State getState() const;
    void setState(State newState); 

    // Read data
    void readGas();

    // Get data
    float getGas();

private:
    // Pins
    const int DATA_PIN;

    // State
    State state;

    // Data
    // My data
    float gas;
};

// Status
const char* mq2StatusToString(Mq2::Status status);

// State
const char* mq2StateToString(Mq2::State state);

#endif