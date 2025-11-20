// Header files
#include <bme280.h>

// Constructor
BME280::BME280(int bme_mosi, int bme_miso, int bme_sck, int bme_cs) :
    // Pins
    BME_MOSI(bme_mosi),
    BME_MISO(bme_miso),
    BME_SCK(bme_sck),
    BME_CS(bme_cs),

    // Library
    bme(bme_cs, bme_mosi, bme_miso, bme_sck),

    // Data
    SEA_LEVEL_PRESSURE_HPA(1010)
{}

 // Initialization
void BME280::begin(){
    bme.begin();
}
