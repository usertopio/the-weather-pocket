#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

// Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class OLEDDisplay {
public:
    // ===== Types & Enums =====
    enum class State {
        INIT,
        DISPLAY_WEATHER_1,
        DISPLAY_WEATHER_2,
        DISPLAY_STATUS,
        DISPLAY_SETTING
    };

    // ===== Constructor & Destructor =====
    OLEDDisplay(int screen_width, int screen_height, int oled_reset);

    // ===== Public Methods =====
    void begin();
    State getState() const;

private:
    // ===== Display Configuration =====
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;
    const int OLED_RESET;

    // ===== State Variables =====
    State state;

    // ===== Display Data =====
    Adafruit_SSD1306 display;
};

#endif