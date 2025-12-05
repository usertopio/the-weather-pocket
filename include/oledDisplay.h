#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

// Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Header files
// Parent coponents
#include "component.h"
// Child coponents
#include "buttonNext.h"
#include "buttonConfirm.h"

// Component instances
extern ButtonNext buttonNext;
extern ButtonConfirm buttonConfirm;

class OledDisplay : public Component {
public:
    // State
    enum class State {
        WELCOME,
        DISPLAY_WEATHER,
        DISPLAY_GAS_TEXT,
        DISPLAY_GAS,
        DISPLAY_LOCATION,
        DISPLAY_SETTING
    };

    // Constructor
    OledDisplay(int oled_sda, int oled_scl, int screen_width, int screen_height, int oled_reset);

    //  Initialization
    void begin();

    // State
    State getState() const;
    void setState(State newState);

    void updateDisplay();

    void resetGap();

    void displayHeader(const char* header_name);

private:
    // Display configuration
    const int OLED_SDA;
    const int OLED_SCL;
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

// My data
extern int y;
extern int gap;

#endif