#ifndef OLEDDISPLAY_H
#define OLEDDISPLAY_H

// Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Header files
#include <sensor.h>

class OLEDDisplay : public Sensor {
    private:
        const int SCREEN_WIDTH;
        const int SCREEN_HEIGHT;
        const int ADDRESS;
        Adafruit_SSD1306 display;
    public:
        OLEDDisplay(int screen_width, int screen_height, int address);
        void begin() override;
};

#endif