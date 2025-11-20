#ifndef OLEDDISPLAY_H
#define OLEDDISPLAY_H

// Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Header files
#include "sensor.h"

class OLEDDisplay : public Sensor {
    // Constructor
    public:
        // Methods
        OLEDDisplay(int screen_width, int screen_height, int address);
    
    // Initialization
    public:
        // Methods
        void begin() override;

    // Pins
    private:
        // Variables
        const int SCREEN_WIDTH;
        const int SCREEN_HEIGHT;
        const int ADDRESS;

    // State
    protected:
        // Variables
        enum class State {
            INIT,
            DISPLAY_WEATHER_1,
            DISPLAY_WEATHER_2,
            DISPLAY_STATUS,
            DISPLAY_SETTING
        };
  
        State state;

    public:
        // Methods
        State getState() const;

    // Data
    private:
        // Variables
        // Library constants
        Adafruit_SSD1306 display;
};

#endif