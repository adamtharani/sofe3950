//
//  utility.c
//  lab_2
//
//  Created by Adam Tharani on 2022-02-21.
//

#include "utility.h"
#include <unistd.h>
#include <stdlib.h>


void cd(char *path) {
    chdir(path);
}

void clr(void) {
    printf("\e[1;1H\e[2J");
}

void dir(char *directory) {
    system("ls -l");
}

void enviorn(void) {
    system("env");
}

void echoCustom(char *string) {
    printf("%s\n", string);
}

void help(void) {
    
}

void pauseCustom(void) {
    
}

void quit(void) {
    
}

void pwd(void) {
    system("pwd");
}
