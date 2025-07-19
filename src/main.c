#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
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

    pthread_mutex_t timer_mutex = PTHREAD_MUTEX_INITIALIZER;    // Used to multithread timer
    pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;

    // SET TIMER DIGITS TO 0
    int *field = (int*)timer; // Treat the struct as an array of ints so we can loop through them
    size_t numFields = sizeof(Timer) / sizeof(int);

    // Now assign 0 to all attributes using pointer arithmetic
    for (int i = 0; i < numFields; i++) {
        *(field + i) = 0;
    }

    // Main Program Loop
    while (isRunning) {
        switch (*program_state) {
            case (PROGRAM_UI_SELECT_TIMER): {
                UI_SelectTimer(timer, timer_mode, program_state);
            } break;

            case (PROGRAM_UI_CONFIGURE_TIMER): {
                UI_ConfigureTimer(timer, timer_mode, program_state);
            } break;

            case (PROGRAM_TIMER_RUNNING): {
                pthread_mutex_lock(&timer_mutex);
                TIMER_COUNT(timer, timer_mode, program_state);
                DisplayTimer(timer);
                pthread_mutex_unlock(&timer_mutex);
            } break;

            case (PROGRAM_TIMER_FINISHED): {

            } break;

            case (PROGRAM_INPUT): {
                pthread_mutex_lock(&timer_mutex);
                UI_Input(timer, program_state);
                pthread_mutex_unlock(&timer_mutex);
            }

            case (PROGRAM_EXIT): {
                isRunning = false;
            } break;
        }
    }

    // Free
    free(isRunning);
    free(isCounting);
    free(timer);
    free(program_state);
    free(timer_mode);

    // Destroy mutex
    pthread_mutex_destroy(&timer_mutex);
    pthread_mutex_destroy(&count_mutex);

    // Clear screen at the end
    Flush();

    return 0;
}