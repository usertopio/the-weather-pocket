#ifndef LED_H
#define LED_H

// State
// Process states
typedef enum
{
    INIT,
    MEASURE,
    DATA,
} ProcessState;

ProcessState currentState;



#endif