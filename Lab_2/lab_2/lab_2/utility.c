#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <termios.h>
#include "utility.h" 


//Break line and store each word as a token
void tokenization (char* string, char lines[][MAXCHARACTERS]){ 
	int count = 0;
	char* token = strtok(string," ");
	while (token != NULL){ 
		strcpy(lines[count], token); 
		count++; 
		token = strtok(NULL, " "); 
	}
	//return count;
}

//Print current working directory
void printDirectory (void){
	char workingDir[MAXCHARACTERS];
	pwd(workingDir);	
	printf("%s# ", workingDir);
}

//get the current working directory path
void pwd(char *workingDirectory) {
    getcwd(workingDirectory, MAXCHARACTERS);
}

//change the directory to this path
void changeDirectory(char *path) {
    chdir(path);
}

//Clear the screen
void clearScreen(void) {
    printf("\e[1;1H\e[2J");
}

//List the content of the directory
void showDirectory(void) {
    system("ls");
}

//Print out all the environment variables
void environmentStrings(void) {
    system("env");
}	

//Print out what the user inputted
void echoCustom(char string[10][1024]) {
	for (int i=1; i<10; i++){
		printf("%s ", string[i]);
	}
	printf("\n");
}

//Print out all the commands in the shell
void help(void) {
	FILE *file;

   if ((file = fopen("readme.txt", "r")) == NULL){
       printf("Error! opening file");
       exit(1);
   }
	system ("more -d -1 readme.txt");
}

//function got from online!
void pauseCustom(void) {
	char buffer[] = {0};
		struct termios term, term_orig;
		tcgetattr(STDIN_FILENO, &term);
		term_orig = term;
		term.c_lflag &= ~ECHO;
		tcsetattr(STDIN_FILENO, TCSANOW, &term);

		//clear the buffer from all the garbage the user entered until enter is pressed
		fflush(stdin);
		fgets(buffer, 256, stdin);

		//re-enables echo from the keystroke presses
		tcsetattr(STDIN_FILENO, TCSANOW, &term_orig);
}

//Quit the shell
void quit(void) {
    exit(0);
}

