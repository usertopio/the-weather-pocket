#ifndef BUTTONCONFIRM_H
#define BUTTONCONFIRM_H

// Header files
#include "component.h"

class ButtonConfirm : public Component {
public:
    // State
    enum class State {
        NOT_PRESSED,
        PRESSED
    };

    // Constructor
    ButtonConfirm(int signal_pin);

    //  Initialization
    void begin() override;

    // State
    State getState() const;
    void setState(State newState); 

private:
    // Pins
    const int SIGNAL_PIN;

    // State
    State state;

    // Data
    // My data
    bool lastButtonConfirmState;
    bool currentButtonConfirmState;
};

#endif