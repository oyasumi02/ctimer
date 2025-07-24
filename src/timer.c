#include "../includes/timer.h"
#include "../includes/util.h"

void TIMER_STOPWATCH(Timer *timer) {
    int *places[] = {
        &timer->secondsOnesPlace,
        &timer->secondsTensPlace,
        &timer->minutesOnesPlace,
        &timer->minutesTensPlace,
        &timer->hoursOnesPlace,
        &timer->hoursTensPlace
    };
    
    SleepSeconds(1);
    timer->secondsOnesPlace++;
            
    if (timer->secondsOnesPlace > 9) {
        timer->secondsOnesPlace = 0;
        timer->secondsTensPlace++;
    }

    if (timer->secondsTensPlace > 5) {
        timer->secondsTensPlace = 0;
        timer->minutesOnesPlace++;
    }

    if (timer->minutesOnesPlace > 9) {
        timer->minutesOnesPlace = 0;
        timer->minutesTensPlace++;
    }

    if (timer->minutesTensPlace > 5) {
        timer->minutesTensPlace = 0;
        timer->hoursOnesPlace++;
    }

    if (timer->hoursOnesPlace > 9) {
        timer->hoursOnesPlace = 0;
        timer->hoursTensPlace++;
    }

    // Reset all numbers to zero if it overflows
    if (timer->hoursTensPlace > 9) {
        for (int i = 0; i < sizeof(places) / sizeof(places[0]); i++) {
            *places[i] = 0;
        }
    }
}

void TIMER_COUNTDOWN(Timer* timer) {

}