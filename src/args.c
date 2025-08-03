#include <string.h>
#include "../includes/args.h"

void ARGS_Parse(int argc, char *argv[], bool *isCounting, PROGRAM_STATE *program_state, TIMER_MODE *timer_mode, TIMER_STATE *timer_state) {

    // STOPWATCH MODE
    if (strcmp(argv[1], "stopwatch") == 0 || strcmp(argv[1], "sw") == 0 || strcmp(argv[1], "s") == 0) {
        *isCounting = true;
        *program_state = PROGRAM_TIMER_RUNNING;
        *timer_mode = TIMER_MODE_STOPWATCH;
        *timer_state = TIMER_STATE_RUNNING;
    } else if (strcmp(argv[1], "countdown") == 0 || strcmp(argv[1], "ct") == 0 || strcmp(argv[1], "c") == 0) {
        *isCounting = true;
        *program_state = PROGRAM_UI_CONFIGURE_TIMER;
        *timer_mode = TIMER_MODE_COUNTDOWN;
        *timer_state = TIMER_STATE_RUNNING;
    }
}