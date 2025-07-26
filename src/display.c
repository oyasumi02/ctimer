#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>
#include "../includes/display.h"
#include "../includes/timer.h"
#include "../includes/util.h"
#include "../includes/state.h"

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
    getchar();

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

void UI_ConfigureTimer(Timer *timer, Timer *original_time, TIMER_MODE *timer_mode, PROGRAM_STATE *state) {
    Flush();
    char selectedMode[16];

    int input_seconds = 0;
    int input_minutes = 0;
    int input_hours = 0;
    int limit = 59;

    switch (*timer_mode) {
        case (TIMER_MODE_STOPWATCH): {
            strcpy(selectedMode, "Stopwatch");
        } break;

        case (TIMER_MODE_COUNTDOWN): {
            strcpy(selectedMode, "Countdown");
        } break;
    }

    // :: { CONFIGURE COUNTDOWN } ::
    if (*timer_mode == TIMER_MODE_COUNTDOWN) {
        printf("{}[]====================[]{}\n");
        printf("    Current Mode: %s        \n", selectedMode);
        printf("{}[]====================[]{}\n");
        printf("++  Set the time          ++\n");
        printf("++  59 is the max         ++\n");
        printf("{}[]====================[]{}\n");
        printf("[ Seconds ] --> ");
        scanf("%d", &input_seconds);
        printf("[ Minutes ] --> ");
        scanf("%d", &input_minutes);
        printf("[ Hours ] --> ");
        scanf("%d", &input_hours);

        // If input is over the limit, cap it to the limit
        if (input_seconds > limit) {
            input_seconds = limit;
        }

        if (input_minutes > limit) {
            input_minutes = limit;
        }

        if (input_hours > limit) {
            input_hours = limit;
        }

        // selectedTime[strcspn(selectedTime, "\n")] = '\0'; // Remove newline

        // Assign digits to timer struct
        if (input_seconds <= limit && input_minutes <= limit && input_hours <= limit) {

            // Assign to timer struct
            timer->seconds = input_seconds;
            timer->minutes = input_minutes;
            timer->hours = input_hours;

            // Then into the original_time copy, where it will be used at the finish screen
            original_time->seconds = input_seconds;
            original_time->minutes = input_minutes;
            original_time->hours = input_hours;
        } else {
            printf("ERROR: Could not assign timer digits to struct\n");
            *state = PROGRAM_EXIT;
        }
    }


    unsigned char confirm = ' '; // This is just for the confirmation screen

    // :: { STOPWATCH CONFIRMATION SCREEN } ::
    if (*timer_mode == TIMER_MODE_STOPWATCH) {
        Flush();
        printf("{}[]============================[]{}\n");
        printf("   Current Mode: %s                 \n", selectedMode);
        printf("{}[]============================[]{}\n");
        printf("    Start the timer? [y/n]          \n");
        printf("{}[]============================[]{}\n");
        printf("--> ");
        scanf(" %c", &confirm);
        confirm = tolower(confirm);
    }

    // :: { COUNTDOWN CONFIRMATION SCREEN } ::
    if (*timer_mode == TIMER_MODE_COUNTDOWN) {
        Flush();
        printf("{}[]============================[]{}\n");
        printf("    Current Mode: %s                \n", selectedMode);
        printf("{}[]============================[]{}\n");
        printf("    %02d:%02d:%02d                  \n",
            timer->hours,
            timer->minutes,
            timer->seconds
        );
        printf("    Set the timer? [y/n]            \n");
        printf("{}[]============================[]{}\n");
        printf("--> ");
        scanf(" %c", &confirm);
        getchar();
        confirm = tolower(confirm);
    }

    switch (confirm) {
        case ('y'): {
            *state = PROGRAM_TIMER_RUNNING;
        } break;

        default: {
            UI_SelectTimer(timer, timer_mode, state);
        } break;
    }
}

void UI_Input(Timer *timer, TIMER_STATE *timer_state, PROGRAM_STATE *program_state) {
    char input[64];
    printf("-->");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove the newline
    if (strcmp(input, "pause")) {
        *timer_state = TIMER_STATE_PAUSED;
    } else if (strcmp(input, "unpause")) {
        *timer_state = TIMER_STATE_PAUSED;
    } else if (strcmp(input, "stop")) {
        *timer_state = TIMER_STATE_PAUSED;
    }
}

void UI_TimerFinished(Timer *timer, Timer *original_time, TIMER_MODE *timer_mode, PROGRAM_STATE *program_state) {
    if (*timer_mode == TIMER_MODE_COUNTDOWN) {
        Flush();
        printf("--+[]================================[]+--\n");
        printf("--+[]         COUNTDOWN DONE         []+--\n");
        printf("--+[]================================[]+--\n");
        printf("         Timer: %02d:%02d:%02d            \n",
            original_time->hours,
            original_time->minutes,
            original_time->seconds
        );
        printf("--+[]================================[]+--\n");
        printf("[Continue] --> ");
        getchar();
    }

    // Clear timer
    timer->seconds = 0;
    timer->minutes = 0;
    timer->hours = 0;

    *program_state = PROGRAM_UI_SELECT_TIMER;
}

void DisplayTimer(Timer *timer) {
    Flush();
    printf("+=============+\n");
    printf("%02d:%02d:%02d \n",
        timer->hours,
        timer->minutes,
        timer->seconds
    );
    printf("+=============+\n");
    fflush(stdout);
}

void DisplayTimerFinished(Timer *timer) {
    
}