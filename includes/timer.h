#ifndef TIMER_H
#define TIMER_H
#include "./state.h"
#include "./mode.h"

typedef struct {
    
    // Format: 00:00:00
    int secondsOnesPlace;
    int secondsTensPlace;

    int minutesOnesPlace;
    int minutesTensPlace;

    int hoursOnesPlace;
    int hoursTensPlace;

} Timer;

void TIMER_COUNT(TIMER_MODE *timer_mode, PROGRAM_STATE *program_state);

#endif