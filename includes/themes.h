#ifndef THEMES_H
#define THEMES_H
#include "./timer.h"

typedef enum {
    TIMER_THEME_NORMAL
} TIMER_THEME;

void THEME_Normal();
void THEME_Big(Timer *timer);

#endif