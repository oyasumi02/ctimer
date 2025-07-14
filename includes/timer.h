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

void MODE_Stopwatch(Timer *timer);
void MODE_Countdown(Timer *timer);

#endif