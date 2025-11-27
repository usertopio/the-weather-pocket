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
    ButtonNext(int DATA_SIGNAL);

    //  Initialization
    void begin() override;

    // State
    State getState() const;
    void setState(State newState);

    // Read signal
    void readSignal();

    // Get signal
    bool getButtonFlag();
    bool getLastButtonNextState();
    bool getCurrentButtonNextState();
    bool isButtonNextPressed();

private:
    // Pins
    const int DATA_SIGNAL;

    // State
    State state;

    // Data
    // My data
    bool isPressed;
    bool lastButtonNextState;
    bool currentButtonNextState;

    
};

#endif