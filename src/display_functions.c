#include "../includes/display_functions.h"

void DISPLAY_TIMER_DEFAULT(Timer *timer) {
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