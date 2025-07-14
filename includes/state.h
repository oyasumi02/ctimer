#ifndef STATE_H
#define STATE_H

typedef enum {
    PROGRAM_UI_SELECT_TIMER = 0,        // Picking the type of timer
    PROGRAM_UI_CONFIGURE_TIMER,         // Setting the digits on the timer
    PROGRAM_TIMER_STOPWATCH_COUNT,      // When the stopwatch is counting up
    PROGRAM_TIMER_STOPWATCH_FINISHED,   // When the stopwatch is done counting up
    PROGRAM_TIMER_COUNTDOWN_COUNT,      // When the countdown timer counts down
    PROGRAM_TIMER_COUNTDOWN_FINISHED,   // When the countdown timer is done
    PROGRAM_EXIT                        // When user exits through the menu
} PROGRAM_STATE;

#endif