#ifndef STATE_H
#define STATE_H

typedef enum {
    PROGRAM_UI_SELECT_TIMER = 0,        // Picking the type of timer
    PROGRAM_UI_CONFIGURE_TIMER,         // Setting the digits on the timer
    PROGRAM_TIMER_RUNNING,              // Begins the count on the timer (Multithreaded)
    PROGRAM_INPUT,                      // Takes input (multithreaded)
    PROGRAM_TIMER_FINISHED,             // When the timer is finished
    PROGRAM_EXIT                        // When user exits through the menu
} PROGRAM_STATE;

typedef enum {
    TIMER_STATE_RUNNING,
    TIMER_STATE_PAUSED,
    Timer_STATE_STOPPED
} TIMER_STATE;

#endif