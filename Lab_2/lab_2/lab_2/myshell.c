#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "utility.h"

int main(int argc, char *argv[]) {
	int readFile = 0;
	char line[MAXCHARACTERS] = {0};
	char command[MAXCHARACTERS] = {0};
	char word[MAXWORDS][MAXCHARACTERS] = {0};

	FILE *batchFile;

	if (argc > 1)
	{
		batchFile = fopen(argv[1], "r");
		if (batchFile == NULL)
		{
			printf("Error, can not open file!!\n");
			exit(0);
		}
		readFile = 1;
	}
	else
	{
		batchFile = stdin;
	}

	printf("\n========C Shell========\n\n");
	
	if (readFile != 1){
		printDirectory();
	}

	while (fgets(line, MAXCHARACTERS, batchFile) != NULL)  {  
		int i = 0; 
		while (line[i] != '\n')
		{
			i++;
		}
		line[i] = '\0';


		tokenization(line, word); //Get the number of words after tokenizing

		strcpy(command, word[0]); //Extract the command word

		if (strcmp(command, "cd") == 0) {
			changeDirectory (word[1]);
			if (readFile == 1){
				printf("\n");
			}
		}

		else if (strcmp(command, "clr") == 0){
			clearScreen();
		}

		else if (strcmp(command, "dir") == 0){
			showDirectory();
		}

		else if (strcmp(command, "echo") == 0){
			echoCustom(word);
		}

		else if (strcmp(command, "help") == 0){
			help();
		}
		
		else if (strcmp(command, "environ") == 0){
			environmentStrings();
		}

		else if (strcmp(command, "pause") == 0){
			pauseCustom();
		}

		else if (strcmp(command, "quit") == 0){
			quit();
		}
		
		//Clear the memory to 0
		memset(line, 0, sizeof line);
		memset(command, 0, sizeof command);
		for (int i = 0; i < MAXWORDS; i++)
		{
			memset(word[i], 0, sizeof word[i]);
		}
		
	 	printDirectory();
	}

}
