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
void tokenize(char *input, char **tokens){
  
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main() //(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    printf("\nWelcome to Jeopardy! (Maximum of 4 players)\n\n");
    initialize_game();

    // Prompt for players names
    for (int count = 0; count < NUM_PLAYERS; count++) {
        printf("Please enter the name for player %i: ", count+1);
        scanf("%s", (char *) &players[count].name);
        printf("\nSuccessfully stored %s as player %i\n\n", players[count].name, count+1);
    }

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        char token[4][BUFFER_LEN] = {{0}};
        int value = 0;
        char userInput[BUFFER_LEN] = {0};
        char *category = malloc(sizeof(char) * 256);

        display_categories();

        category = "algorithms";
        value = 400;

        /* DO NOT DELETE!
        printf("\nEnter category: ");
        scanf("%s", category);

        printf("Enter value: ");
        scanf("%d", &value);
        */

        display_question(category, value);
        update_score(players, NUM_PLAYERS, "Abdul", value);

        printf("name: %s\n", players[0].name);
        printf("score: %d\n", players[0].score);

       

        // Call functions from the questions and players source files

        // Execute the game until all questions are answered


        // Display the final results and exit
        free(category);
    }
    return EXIT_SUCCESS;
}

