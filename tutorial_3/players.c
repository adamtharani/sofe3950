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
#include "players.h"

// Returns true if the player name matches one of the existing players
bool player_exists(player *players, int num_players, char *name)
{
    for (int i = 1; i <= num_players; i++){
        if (strcasecmp(players[i].name, name) == 0) {
            printf("works");
            return true;
        }
    }
    return false;
}

// Go through the list of players and update the score for the 
// player given their name
void update_score(player *players, int num_players, char *name, int score)
{
    for (int i = 1; i <= num_players; i++) {
        if (strcasecmp(players[i].name, name) == 0) {
            players[i].score = score;
        }
    }
}

void ordered_by_points(player *players, int num_players) {
    printf("\n=====SCOREBOARD======\n");
    
    
    
    for(int i = 1; i <= num_players - 1; i++){
           for(int j = 0; j < num_players - i - 1; j++){
               if(players[j].score < players[j+1].score){
                   player temp;
                   temp = players[j];
                   players[j] = players[j+1];
                   players[j+1] = temp;
               }
           }
       }

       bool tie = false;
       int score = players[0].score;

       for(int i = 1; i <= num_players; i++){
           if (score == players[i].score)
               tie = true;
               break;
       }

       if (tie) {
           printf("%s: %d\n", players[0].name, players[0].score);
       } else {
           printf("%s: %d - WINNER!!\n", players[0].name, players[0].score);
       }

//       for(int i = 0; i < num_players; i ++){
//           
//           printf("%s: %d\n", players[i].name, players[i].score);
//       }
}
