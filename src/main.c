#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../includes/util.h"
#include "../includes/timer.h"
#include "../includes/display.h"
#include "../includes/state.h"

int main(int arc, char *argv[]) {

    // Important Variables
    bool *isRunning = (bool*)malloc(sizeof(bool));
    PROGRAM_STATE program_state = PROGRAM_UI_SELECT_TIMER;
    if (isRunning == NULL) {
        printf("ERROR: Failed to allocate isRunning bool\n");
        return 1;
    }

    // Malloc timer struct
    Timer *timer = (Timer*)malloc(sizeof(Timer));
    if (timer == NULL) {
        printf("ERROR: Failed to allocate Timer struct\n");
        return 1;
    }

    // || Initialize attributes ||
    int *field = (int*)timer; // We treat the pTimer struct as an array of ints
    size_t numFields = sizeof(Timer) / sizeof(int);

    // Now assign 0 to all attributes using pointer arithmetic
    for (int i = 0; i < numFields; i++) {
        *(field + i) = 0;
    }

    while (isRunning) {
        switch (program_state) {
            case (PROGRAM_UI_SELECT_TIMER): {

            } break;

            case (PROGRAM_UI_CONFIGURE_TIMER): {

            } break;

            case (PROGRAM_TIMER_STOPWATCH_COUNT): {

            } break;

            case (PROGRAM_TIMER_STOPWATCH_FINISHED): {

            } break;

            case (PROGRAM_TIMER_COUNTDOWN_COUNT): {

            } break;

            case (PROGRAM_TIMER_COUNTDOWN_FINISHED): {

            } break;

            case (PROGRAM_EXIT): {
                isRunning = false;
            } break;
        }
    }

    // Free
    free(timer);

    return 0;
}