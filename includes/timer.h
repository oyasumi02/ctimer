#ifndef TIMER_H
#define TIMER_H
#include "./state.h"
#include "./mode.h"

typedef struct {
    unsigned short int hours;
    unsigned short int minutes;
    unsigned short int seconds;
} Timer;

void TIMER_STOPWATCH(Timer *timer);
void TIMER_COUNTDOWN(Timer *timer);

#endif