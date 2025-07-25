#include "../includes/timer.h"
#include "../includes/util.h"

void TIMER_STOPWATCH(Timer *timer) {
    timer->seconds++;

    if (timer->seconds > 59) {
        timer->seconds = 0;
        timer->minutes++;
    }

    if (timer->minutes > 59) {
        timer->minutes = 0;
        timer->hours++;
    }

    if (timer->hours > 99) {
        timer->seconds = 0;
        timer->minutes = 0;
        timer->hours = 0;
    }

    SleepSeconds(1);
}

void TIMER_COUNTDOWN(Timer* timer) {

}