#include <stdio.h>
#include <unistd.h>
#include "../includes/util.h"

void SleepSeconds(int sec) {
    sleep(sec);
}

void Flush(void){
    printf("\033[2J\033[H");
    fflush(stdout);
}

void ClearBufferOverflow(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void LowerString(char *s) {
    while (*s) {
        *s = tolower(*s);
        s++;
    }
}