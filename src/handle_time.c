#include <stdbool.h>
#include "../includes/handle_time.h"
#include "../includes/timer.h"
#include "../includes/util.h"

void TIME_CountTime(Timer *timer, TIMER_MODE *timer_mode, TIMER_STATE *timer_state, PROGRAM_STATE *program_state) {

    // STOPWATCH MODE
    if (*timer_mode == TIMER_MODE_STOPWATCH) {
        if (*timer_state == TIMER_STATE_RUNNING) {
            TIMER_STOPWATCH(timer);
        }
    }

    if (*timer_mode == TIMER_MODE_COUNTDOWN) {
        if (*timer_state == TIMER_STATE_RUNNING) {
            TIMER_COUNTDOWN(timer, program_state);
        }
    }
}