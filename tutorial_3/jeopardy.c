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
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens)
{
    char *token;

    token = strtok(input, " ");

    if (token != NULL)
    {
        if (strcasecmp(token, "who") != 0 && strcasecmp(token, "what") != 0)
        {
            return;
        }
    }

    token = strtok(NULL, " ");

    if (token != NULL)
    {
        if (strcasecmp(token, "is") != 0)
        {
            return;
        }
    }

    *tokens = strtok(NULL, "\n");
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players)
{
    for (int i = 1; i <= NUM_PLAYERS; i++)
    {
        printf("Name: %s    Score: %d\n", players[i].name, players[i].score);
    }
}

int main() //(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];

    // Input buffer and and commands
    char buffer[BUFFER_LEN] = {0};

    // Display the game introduction and initialize the questions
    printf("\nWelcome to Jeopardy! (Maximum of %d players)\n\n", NUM_PLAYERS);
    initialize_game();
    int numberOfPlayersInputed;
    printf("Please enter the amount of players: ");
    scanf("%d", &numberOfPlayersInputed);

    for (int count = 1; count <= numberOfPlayersInputed; count++)
    {

        char name[256];
        printf("Please enter the name for player %i:\n", count);
        scanf("%s", name);
        player p;
        strcpy(p.name, name);
        p.score = 0;
        players[count] = p;
        printf("Successfully stored %s as player %i\n\n", name, count);
    }
    int playerCounter;
    int questions_remaining = sizeof(questions);
    
    //     Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        while (questions_remaining >= 0)
        {
            char playersName[BUFFER_LEN];
            bool playerMatched = false;
            printf("Please enter your name: ");
            scanf("%s", playersName);

            for (int counter = 1; counter <= numberOfPlayersInputed; counter++)
            {
                if (strcmp(players[counter].name, playersName) == false )
                {
                    playerMatched = true;
                    playerCounter = counter;
                }
            }

            if (playerMatched == false)
            {
                printf("You have entered an invalid players name\n");
            }
            else
            {
                player currentPlayer = players[playerCounter];
                printf("The current player is %s\n\n", currentPlayer.name);
                char categorySelection[BUFFER_LEN];
                int valueSelection;
                char answer[BUFFER_LEN];
                display_categories();
                printf("Please pick a category: \n");
                scanf("%s", categorySelection);
                printf("Please pick a value: \n");
                scanf("%i", &valueSelection);
                display_question(categorySelection, valueSelection);
                fflush(stdin);
                printf("Please enter your answer: \n");
                scanf("%[^\n]s", answer);
                char *tokenizedAnswer;
                tokenize(answer, &tokenizedAnswer);
                if (valid_answer(categorySelection, valueSelection, tokenizedAnswer))
                {
                    printf("\nYou answered right\n");
                    update_score(players, numberOfPlayersInputed, currentPlayer.name, currentPlayer.score + valueSelection);
                    show_results(players);
                }
                else
                {
                    display_answer(categorySelection, valueSelection);
                }

                mark_question_answered(categorySelection, valueSelection);
                questions_remaining--;
            }
        }
        //        ordered_by_points(players, NUM_PLAYERS);
    }
    return EXIT_SUCCESS;
}
