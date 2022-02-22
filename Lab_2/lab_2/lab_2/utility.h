#ifndef utility_h
#define utility_h

#include <stdio.h>

// defining contants 
#define MAXCHARACTERS 1024
#define MAXWORDS 3

void tokenization(char* str, char lines[][MAXCHARACTERS]);
void printDirectory (void);
void pwd(char *workingDirectory);
void changeDirectory(char *path);
void clearScreen(void);
void showDirectory(void);
void environmentStrings(void);
void echoCustom(char string[10][1024]);
void help(void);
void pauseCustom(void);
void quit(void);

#endif /* utility_h */