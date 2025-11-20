// Header files
#include "oledDisplay.h"

// Constructor
OLEDDisplay::OLEDDisplay(int screen_width, int screen_height, int address): 
    // Pins
    SCREEN_WIDTH(screen_width), 
    SCREEN_HEIGHT(screen_height), 
    ADDRESS(address),

    // State
    state(State::INIT),

    // Library
    display(screen_width, screen_height, &Wire, -1)
{}

// Initialization
void OLEDDisplay::begin(){
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    status = Status::ON;
}

// State
OLEDDisplay::State OLEDDisplay::getState() const {
    return state;
}