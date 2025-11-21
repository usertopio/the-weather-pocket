#ifndef SYSTEM_H
#define SYSTEM_H

// State
enum class SystemState {
    INIT,
    MEASURE_BME280,
    MEASURE_MQ2,
    MEASURE_NEO6M,
    PROCESS_DATA,
    UPLOAD_DATA
};

extern SystemState systemState;

// Serial monitor
void monitor(float dht_temp, float dht_humid, DHTSensor::Status component_status, DHTSensor::State component_state);

#endif