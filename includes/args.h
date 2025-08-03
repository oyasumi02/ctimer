#ifndef ARGS_H
#define ARGS_H
#include <stdbool.h>
#include "./state.h"
#include "./mode.h"
#include "./timer.h"

void ARGS_Parse(int argc, char *argv[], bool *isCounting, PROGRAM_STATE *program_state, TIMER_MODE *timer_mode, TIMER_STATE *timer_state);

#endif