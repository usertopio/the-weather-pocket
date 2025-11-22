// Header files
#include "oledDisplay.h"

// Constructor
OledDisplay::OledDisplay(int screen_width, int screen_height, int address):   
    // Display configuration
    SCREEN_WIDTH(screen_width),
    SCREEN_HEIGHT(screen_height),
    ADDRESS(address),
    OLED_RESET(-1),
    // State
    state(State::INIT),
    // Libraries
    display(screen_width, screen_height, &Wire, OLED_RESET)
{}

// Initialization
void OledDisplay::begin(){
    // Libraries
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    // State
    status = Status::ON;
}

// State
OledDisplay::State OledDisplay::getState() const {
    return state;
}

void OledDisplay::setState(State newState) {
    state = newState;
}