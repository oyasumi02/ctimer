#include "../includes/timer.h"
#include "../includes/util.h"
#include "../includes/state.h"

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

void TIMER_COUNTDOWN(Timer* timer, PROGRAM_STATE *program_state) {
          
    if (timer->hours == 0 && timer->minutes == 0 && timer->seconds == 0) {
        *program_state = PROGRAM_TIMER_FINISHED;
        return;
    }

    if (timer->seconds > 0) {
        timer->seconds--;
    } else {
        if (timer->minutes > 0) {
            timer->minutes--;
            timer->seconds = 59;
        } else if (timer->hours > 0) {
            timer->hours--;
            timer->minutes = 59;
            timer->seconds = 59;
        }
    }
    SleepSeconds(1);
}