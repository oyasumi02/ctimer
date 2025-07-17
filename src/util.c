#include <stdio.h>
#include <unistd.h>
#include "../includes/util.h"

void SleepSeconds(int sec) {
    sleep(sec);
}

void Flush(){
    printf("\033[2J\033[H");
    fflush(stdout);
}