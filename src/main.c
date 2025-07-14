#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../includes/util.h"
#include "../includes/timer.h"
#include "../includes/display.h"

int main() {

    // Flags
    // bool isRunning = true;

    // Malloc timer struct
    Timer *pTimer = (Timer*)malloc(sizeof(Timer));
    if (pTimer == NULL) {
        printf("ERROR: Failed to allocate Timer struct\n");
        return 1;
    }

    // || Initialize attributes ||
    int *field = (int*)pTimer; // We treat the pTimer struct as an array of ints
    size_t numFields = sizeof(Timer) / sizeof(int);

    // Now assign 0 to all attributes using pointer arithmetic
    for (int i = 0; i < numFields; i++) {
        *(field + i) = 0;
    }

    DisplayTimer(*pTimer);

    // Free
    free(pTimer);

    return 0;
}