#ifndef BUTTONOLEDDISPLAY_H
#define BUTTONOLEDDISPLAY_H

// Header files
#include "component.h"

class ButtonOledDisplay : public Component {
public:
    // State
    enum class State {
        NOT_PRESSED,
        PRESSED
    };

    // Constructor
    ButtonOledDisplay(int data_pin);

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
    float lastButtonOledDisplayState;
    float currentButtonOledDisplayState;
};

#endif