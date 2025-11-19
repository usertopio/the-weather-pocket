#include <oledDisplay.h>

OLEDDisplay::OLEDDisplay(int screen_width, int screen_height, int address): 
    SCREEN_WIDTH(screen_width), 
    SCREEN_HEIGHT(screen_height), 
    ADDRESS(address), 
    display(screen_width, screen_height, &Wire, -1){}

void OLEDDisplay::begin(){
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}