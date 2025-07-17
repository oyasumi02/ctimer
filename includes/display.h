#ifndef DISPLAY_H
#define DISPLAY_H
#include "./timer.h"
#include "./state.h"
#include "./mode.h"
#include <stdbool.h>

// UI
void UI_SelectTimer(Timer *timer, TIMER_MODE *timer_mode,PROGRAM_STATE *state);
void UI_ConfigureTimer(Timer *timer, TIMER_MODE *timer_mode, PROGRAM_STATE *program_state);
void UI_Input(Timer *timer, PROGRAM_STATE *program_state);

// Timer
void DisplayTimer(Timer *timer);

#endif