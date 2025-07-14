#ifndef TIMER_H
#define TIMER_H

typedef struct {
    
    // Format: 00:00:00
    int secondsOnesPlace;
    int secondsTensPlace;

    int minutesOnesPlace;
    int minutesTensPlace;

    int hoursOnesPlace;
    int hoursTensPlace;

} Timer;

#endif