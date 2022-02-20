/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 1

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    
    for (int count = 1; count <= NUM_PLAYERS; count++) {
        char name[256];
        printf("Please enter the name for player %i:\n", count);
        scanf("%s", name);
        player p;
        strcpy(p.name, name);
        p.score = 0;
        players[count] = p;
        printf("Successfully stored %s as player %i\n\n", name, count);
    }

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        char token[4][BUFFER_LEN] = {{0}};
        char categorySelection[BUFFER_LEN];
        int valueSelection;
        char answer[BUFFER_LEN];
        display_categories();
        printf("Please pick a category\n");
        scanf("%s", categorySelection);
        printf("Please pick a value\n");
        scanf("%i", &valueSelection);
        display_question(categorySelection, valueSelection);
        printf("Please enter your answer:\n");
        scanf("%[^\n]", answer);
        if (valid_answer(categorySelection, valueSelection, answer)) {
            printf("You answered right");
        }
        else {
            printf("%s", answer);
        }
        
    }
    return EXIT_SUCCESS;
}

