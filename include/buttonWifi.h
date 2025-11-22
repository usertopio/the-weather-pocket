#ifndef BUTTONWIFI_H
#define BUTTONWIFI_H

// Header files
#include "component.h"

class ButtonWifi : public Component {
public:
    // State
    enum class State {
        NOT_PRESSED,
        PRESSED
    };

    // Constructor
    ButtonWifi(int signal_pin);

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
    bool lastButtonWifiState;
    bool currentButtonWifiState;
};

#endif