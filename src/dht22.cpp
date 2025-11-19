#include <dht22.h>

DHT22::DHT22(int dht22_pin, int dht_type): 
    DHT22_PIN(dht22_pin), 
    DHT_TYPE(dht_type),  
    dht(dht22_pin, dht_type) {}

void DHT22::begin(){
    DHT dht(DHT22_PIN, DHT_TYPE);
}