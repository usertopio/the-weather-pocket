// Header files
#include <bme280.h>

// Constructor
BME280::BME280(int bme_mosi, int bme_miso, int bme_scl, int bme_cs):
    BME_MOSI(bme_mosi),
    BME_MISO(bme_miso),
    BME_SCK(bme_scl),
    BME_CS(bme_cs),

    SEA_LEVEL_PRESSURE_HPA(1010),

    bme(bme_cs, bme_mosi, bme_miso, bme_scl) {}

 // Initialization
void BME280::begin(){
    bme.begin();
}
