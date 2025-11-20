// Header files
#include <dht22.h>

// Constructor
DHT22::DHT22(int dht22_pin, int dht_type)
    : DHT22_PIN(dht22_pin),
      DHT_TYPE(dht_type),
      dht(dht22_pin, dht_type),
      state(State::INIT)   // <-- Always initialize state!
{}

// Initialization
void DHT22::begin() {
    dht.begin();
}

// State
DHT22::State DHT22::getState() const {
    return state;
}
