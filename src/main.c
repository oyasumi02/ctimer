#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../includes/util.h"
#include "../includes/timer.h"
#include "../includes/display.h"
#include "../includes/state.h"
#include "../includes/mode.h"

int main(int arc, char *argv[]) {

    // Important Variables
    bool *isRunning = (bool*)malloc(sizeof(bool));
    if (isRunning == NULL) {
        printf("ERROR: Failed to allocate isRunning bool\n");
        return 1;
    }

    bool *isCounting = (bool*)malloc(sizeof(bool));
    if (isCounting == NULL) {
        printf("ERROR: Failed to allocate isCounting bool\n");
        return 1;
    }

    // Malloc timer struct
    Timer *timer = (Timer*)malloc(sizeof(Timer));
    if (timer == NULL) {
        printf("ERROR: Failed to allocate Timer struct\n");
        return 1;
    }

    // Initialize State and Mode enums
    PROGRAM_STATE *program_state = malloc(sizeof(PROGRAM_STATE));
    if (program_state == NULL) {
        printf("ERROR: Failed to allocate program_state enum\n");
        return 1;
    }

    TIMER_MODE *timer_mode = malloc(sizeof(TIMER_MODE));
    if (timer_mode == NULL) {
        printf("ERROR: failed to allocate timer_mode enum\n");
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
        switch (*program_state) {
            case (PROGRAM_UI_SELECT_TIMER): {
                UI_SelectTimer(timer, timer_mode, program_state, isRunning);
            } break;

            case (PROGRAM_UI_CONFIGURE_TIMER): {
                UI_ConfigureTimer(timer, timer_mode, program_state);
            } break;

            case (PROGRAM_TIMER_COUNT): {
                
            }

            case (PROGRAM_EXIT): {
                isRunning = false;
            } break;
        }
    }

    // Free
    free(isRunning);
    free(timer);

    return 0;
}