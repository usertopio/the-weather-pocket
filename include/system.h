#ifndef SYSTEM_H
#define SYSTEM_H

enum class SystemState {
    INIT,
    MEASURE_BME280,
    MEASURE_MQ2,
    MEASURE_GPS,
    PROCESS_DATA,
    UPLOAD_DATA
};

extern SystemState systemState;

#endif