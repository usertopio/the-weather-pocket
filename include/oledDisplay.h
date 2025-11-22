#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

// Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Header files
#include "sensor.h"

class OledDisplay : public Sensor {
public:
    // State
    enum class State {
        INIT,
        DISPLAY_WEATHER,
        DISPLAY_NEO6M,
        DISPLAY_SETTING
    };

    // Constructor
    OledDisplay(int screen_width, int screen_height, int oled_reset);

    //  Initialization
    void begin();

    // State
    State getState() const;
    void setState(State newState); 

private:
    // Display configuration
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;
    const int ADDRESS;
    const int OLED_RESET;

    // State
    State state;

    // Data
    // Libraries
    Adafruit_SSD1306 display;
};

#endif