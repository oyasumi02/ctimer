#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>
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

void UI_ConfigureTimer(Timer *timer, TIMER_MODE *timer_mode, PROGRAM_STATE *state) {
    Flush();
    char selectedTime[9]; // 9 is the size of "00:00:00" plus \0
    char selectedMode[16];
    size_t length = strlen(selectedTime);

    switch (*timer_mode) {
        case (TIMER_MODE_STOPWATCH): {
            strcpy(selectedMode, "Stopwatch");
        } break;

        case (TIMER_MODE_COUNTDOWN): {
            strcpy(selectedMode, "Countdown");
        } break;
    }

    printf("{}[]====================[]{}\n");
    printf("++ Current Mode: %s       ++\n", selectedMode);
    printf("{}[]====================[]{}\n");
    printf("++ Set the time           ++\n");
    printf("++ Format: 00:00:00       ++\n");
    printf("{}[]====================[]{}\n");
    printf("--> ");
    fgets(selectedTime, sizeof(selectedTime), stdin);
    selectedTime[strcspn(selectedTime, "\n")] = '\0'; // Remove newline

    // Check Length
    if (strlen(selectedTime) != 8) {
        Flush();
        printf("Incorrect format length, should exactly match: 00:00:00\n");
        SleepSeconds(3);
        UI_ConfigureTimer(timer, timer_mode, state);
        return;
    }

    // Check Formatting is exactly correct
    if (selectedTime[2] == ':' && selectedTime[5] == ':') {
        for (int i = 0; i < length; i++) {
            if (i != 2 && i != 5) {
                if (!isdigit(selectedTime[i])) {
                    Flush();
                    printf("Invalid digits, should exactly match: 00:00:00\n");
                    SleepSeconds(3);
                    UI_ConfigureTimer(timer, timer_mode, state);
                    return;
                }
            }
        }
    } else {
        Flush();
        printf("Invalid format, did you remember to insert ':'?");
        SleepSeconds(3);
        UI_ConfigureTimer(timer, timer_mode, state);
        return;
    }

    // Assign digits to timer struct
    timer->hoursTensPlace = selectedTime[0] - '0';
    timer->hoursOnesPlace = selectedTime[1] - '0';
    timer->minutesTensPlace = selectedTime[3] - '0';
    timer->minutesOnesPlace = selectedTime[4] - '0';
    timer->secondsTensPlace = selectedTime[6] - '0';
    timer->secondsOnesPlace = selectedTime[7] - '0';

    unsigned char confirm = ' '; // This is just for the confirmation screen

    // Confirmation Screen
    printf("{}[]============================[]{}\n");
    printf("++ Current Mode: %s               ++\n", selectedMode);
    printf("{}[]============================[]{}\n");
    printf("   %d%d:%d%d:%d%d                     ",
        timer->hoursTensPlace,
        timer->hoursOnesPlace,
        timer->minutesTensPlace,
        timer->minutesOnesPlace,
        timer->secondsTensPlace,
        timer->secondsOnesPlace
    );
    printf("++ Set the timer? [y/n]           ++\n");
    printf("{}[]============================[]{}\n");
    printf("--> ");
    scanf(" %c", &confirm);
    getchar();
    confirm = tolower(confirm);

    switch (confirm) {
        case ('y'): {
            *state = PROGRAM_TIMER_RUNNING;
        } break;

        default: {
            UI_SelectTimer(timer, timer_mode, state);
        }
    }
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