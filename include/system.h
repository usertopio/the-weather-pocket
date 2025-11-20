#ifndef SYSTEM_H
#define SYSTEM_H

typedef enum {
    INIT,
    MEASURE,
    DATA
} SystemState;

extern SystemState currentState;

#endif