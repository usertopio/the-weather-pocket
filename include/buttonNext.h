#ifndef BUTTONNEXT_H
#define BUTTONNEXT_H

// Header files
#include "component.h"

class ButtonNext : public Component {
public:
    // State
    enum class State {
        NOT_PRESSED,
        PRESSED
    };

    // Constructor
    ButtonNext(int data_pin);

    //  Initialization
    void begin() override;

    // State
    State getState() const;
    void setState(State newState); 

private:
    // Pins
    const int DATA_PIN;

    // State
    State state;

    // Data
    // My data
    bool lastButtonNextState;
    bool currentButtonNextState;
};

#endif