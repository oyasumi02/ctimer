#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include "../includes/display.h"
#include "../includes/timer.h"
#include "../includes/util.h"

void UI_SelectTimer(Timer *timer, TIMER_MODE *timer_mode, PROGRAM_STATE *state) {
    Flush();
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
            *timer_mode = TIMER_MODE_STOPWATCH;
            *state = PROGRAM_UI_CONFIGURE_TIMER;
        } break;

        case 2: {
            *timer_mode = TIMER_MODE_COUNTDOWN;
            *state = PROGRAM_UI_CONFIGURE_TIMER;
        } break;

        case 0: {
            *state = PROGRAM_EXIT;
        } break;

        default: {
            Flush();
            printf("%d is an invalid option!\n", input);
            SleepSeconds(3);
            UI_SelectTimer(timer, timer_mode, state);
        } break;
    }
}

void UI_ConfigureTimer(Timer *timer, TIMER_MODE *timer_mode, PROGRAM_STATE *state) {
    Flush();
    char *userInput = "";
    char *selectedMode = "NONE";

    switch (*timer_mode) {
        case (TIMER_MODE_STOPWATCH): {
            selectedMode = "Stopwatch";
        } break;

        case (TIMER_MODE_COUNTDOWN): {
            selectedMode = "Countdown";
        } break;
    }

    printf("{}[]====================[]{}\n");
    printf("++ Current Mode: %s       ++\n", selectedMode);
    printf("{}[]====================[]{}\n");
    printf("++ Set the time           ++\n");
    printf("++ Format: 00:00:00       ++\n");
    printf("{}[]====================[]{}\n");
    printf("--> ");
    scanf("%s", userInput);
}

void UI_Input(Timer *timer, PROGRAM_STATE *program_state) {

}

void DisplayTimer(Timer *timer) {
    Flush();
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