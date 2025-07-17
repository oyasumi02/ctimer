#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include "../includes/display.h"
#include "../includes/timer.h"

void UI_SelectTimer(Timer *timer, TIMER_MODE *timer_mode, PROGRAM_STATE *state, bool *isRunning) {
    int input = 0;
    printf("    :: | ctimer | ::    \n");
    printf("[]====================[]\n");
    printf("[]   Select a mode    []\n");
    printf("[]====================[]\n");
    printf("[] 1 | Stopwatch      []\n");
    printf("[] 2 | Countdown      []\n");
    printf("[]====================[]\n");
    printf("[] 0 | Exit Program   []\n");
    printf("[]====================[]\n");
    printf("--> ");
    scanf("%d", &input);

    switch (input) {
        case 1: {
            *state = PROGRAM_UI_CONFIGURE_TIMER;
        } break;

        case 2: {
            
        } break;

        case 3: {
            *isRunning = false;
        }
    }
}

void UI_ConfigureTimer(Timer *timer, TIMER_MODE *timer_mode, PROGRAM_STATE *state) {
    
}

void DisplayTimer(Timer *timer) {
    printf("+=============+\n");
    printf("%d%d:%d%d:%d%d\n",
        timer->hoursTensPlace,
        timer->hoursOnesPlace,
        timer->minutesTensPlace,
        timer->minutesOnesPlace,
        timer->secondsTensPlace,
        timer->secondsOnesPlace
    );
    printf("+=============+\n");
    fflush(stdout);
}