#include <led.h>

LED::LED(int led_pin): 
    LED_PIN(led_pin) {}

void LED::begin(){
    pinMode(LED_PIN, OUTPUT);
}