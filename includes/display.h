#ifndef DISPLAY_H
#define DISPLAY_H
#include "./timer.h"
#include <stdbool.h>

// UI
void UI_SelectTimer(Timer *timer, bool *isRunning);
void UI_ConfigureTimer(Timer *timer);

// Timer
void DisplayTimer(Timer *timer);

#endif