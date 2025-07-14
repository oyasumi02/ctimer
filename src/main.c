#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../includes/util.h"
#include "../includes/timer.h"
#include "../includes/display.h"
#include "../includes/state.h"

int main() {

    // Important Variables
    bool isRunning = true;
    PROGRAM_STATE program_state = PROGRAM_UI_SELECT_TIMER;

    // Malloc timer struct
    Timer *pTimer = (Timer*)malloc(sizeof(Timer));
    if (pTimer == NULL) {
        printf("ERROR: Failed to allocate Timer struct\n");
        return 1;
    }

    // || Initialize attributes ||
    int *field = (int*)pTimer; // We treat the pTimer struct as an array of ints
    size_t numFields = sizeof(Timer) / sizeof(int);

    // Now assign 0 to all attributes using pointer arithmetic
    for (int i = 0; i < numFields; i++) {
        *(field + i) = 0;
    }

    while (isRunning) {
        switch (program_state) {
            case (PROGRAM_UI_SELECT_TIMER): {

            }

            case (PROGRAM_UI_CONFIGURE_TIMER): {

            }

            case (PROGRAM_TIMER_STOPWATCH_COUNT): {

            }

            case (PROGRAM_TIMER_STOPWATCH_FINISHED): {

            }

            case (PROGRAM_TIMER_COUNTDOWN_COUNT): {

            }

            case (PROGRAM_TIMER_COUNTDOWN_FINISHED): {

            }

            case (PROGRAM_EXIT): {
                isRunning = false;
            }
        }
    }

    // Free
    free(pTimer);

    return 0;
}