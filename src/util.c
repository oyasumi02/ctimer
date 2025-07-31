#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
void SleepSeconds(unsigned int time) {
    Sleep(time * 1000);
}

void Flush(void) {
    system("cls");
}

#else
#include <unistd.h>
#include "../includes/util.h"

void SleepSeconds(unsigned int time) {
    sleep(time);
}


void Flush(void){
    printf("\033[2J\033[H");
    fflush(stdout);
}

#endif

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