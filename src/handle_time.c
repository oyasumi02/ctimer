#include <stdbool.h>
#include "../includes/handle_time.h"
#include "../includes/timer.h"
#include "../includes/util.h"

void TIME_CountTime(Timer *timer, TIMER_MODE *timer_mode, TIMER_STATE *timer_state) {

    // STOPWATCH MODE
    if (*timer_mode == TIMER_MODE_STOPWATCH) {
        while (*timer_state == TIMER_STATE_RUNNING) {

        }
    }

    if (*timer_mode == TIMER_MODE_COUNTDOWN) {
        while (*timer_state == TIMER_STATE_RUNNING) {

        }
    }
}