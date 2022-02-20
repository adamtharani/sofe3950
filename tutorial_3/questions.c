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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    
    // "programming", 
    //"algorithms", 
    //"databases"
    question q1;
    q1.value = 100;
    strcpy(q1.category, categories[0]);
    strcpy(q1.question, "This is used to write instructions for the computer. A computer executes a sequence of instructions (a program) in order to perform some task.");
    strcpy(q1.answer, "What is a programming language?");
    q1.answered = false;
    questions[0] = q1;

    question q2;
    q2.value = 200;
    strcpy(q2.category, categories[0]);
    strcpy(q2.question, "The data that you put into the computer system for processing.");
    strcpy(q2.answer, "What is a input?");
    q2.answered = false;
    questions[1] = q2;

    question q3;
    q3.value = 300;
    strcpy(q3.category, categories[0]);
    strcpy(q3.question, "Any data that can be true/false");
    strcpy(q3.answer, "What is a boolean?");
    q3.answered = false;
    questions[2] = q3;

    question q4;
    q4.value = 400;
    strcpy(q4.category, categories[0]);
    strcpy(q4.question, "a container for storing values, information or data in general. The information inside them can be used and changed.");
    strcpy(q4.answer, "What is a variable?");
    q4.answered = false;
    questions[3] = q4;

    question q5;
    q5.value = 100;
    strcpy(q5.category, categories[1]);
    strcpy(q5.question, "A well defined procedure solve a problem");
    strcpy(q5.answer, "What is a Algorithm?");
    q5.answered = false;
    questions[4] = q5; 

    question q6;
    q6.value = 200;
    strcpy(q6.category, categories[1]);
    strcpy(q6.question, "a sequence that gets executed multiple times");
    strcpy(q6.answer, "What is a loop?");
    q6.answered = false;
    questions[5] = q6; 

    question q7;
    q7.value = 300;
    strcpy(q7.category, categories[1]);
    strcpy(q7.question, "A body of code that has a specific functionality");
    strcpy(q7.answer, "What is a method?");
    q7.answered = false;
    questions[6] = q7; 

    question q8;
    q8.value = 400;
    strcpy(q8.category, categories[1]);
    strcpy(q8.question, "an algorithm that repeatedly swapping the previous elements if they are in the wrong order");
    strcpy(q8.answer, "What is a bubble sort?");
    q8.answered = false;
    questions[7] = q8; 

    question q9;
    q9.value = 100;
    strcpy(q9.category, categories[2]);
    strcpy(q9.question, "Each row in access");
    strcpy(q9.answer, "What is a record?");
    q9.answered = false;
    questions[8] = q9; 

    question q10;
    q10.value = 200;
    strcpy(q10.category, categories[2]);
    strcpy(q10.question, "an organized collection of information");
    strcpy(q10.answer, "What is a database?");
    q10.answered = false;
    questions[9] = q10; 

    question q11;
    q11.value = 300;
    strcpy(q11.category, categories[2]);
    strcpy(q11.question, "Link data between tables for queries");
    strcpy(q11.answer, "What is a relationship/>");
    q11.answered = false;
    questions[10] = q11; 

    question q12;
    q12.value = 400;
    strcpy(q12.category, categories[2]);
    strcpy(q12.question, "A different parts of each record");
    strcpy(q12.answer, "What is a field??");
    q12.answered = false;
    questions[11] = q12; 
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    char tempQuestions[12][20];
    
    for (int i =0; i<12; i++){
        if (questions[i].answered == false){
            snprintf(tempQuestions[i], 20, "%d", questions[i].value);
        }

        else {
            strcpy(tempQuestions[i], "---");
        }
    }
    // print categories and dollar values for each unanswered question in questions array

    printf("    %s  |   %s   |   %s  \n", categories[0], categories[1], categories[2]);
    printf("--------------------------------------------------\n");
    for (int i=0; i<4; i++){
            printf("       %s       |       %s      |      %s             \n", tempQuestions[i], tempQuestions[i+4], tempQuestions[i+8]);
            printf("--------------------------------------------------\n");
    }
    printf("\n");
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    printf("\nYou choose %s for $%d \n", category, value);
    
    for (int i=0; i<12; i++){
        //If the value of category and value match return the question number
        if (strcmp (questions[i].category, category) == 0 && (questions[i].value == value)){
            printf("Question: %s\n\n", questions[i].question);
        }
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0) {
            if (questions[i].value == value)
                if (strcmp(questions[i].answer, answer) == 0) {
                    return true;;
                }
        }
    }
	return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    //Go through each category
    for (int i=0; i<12; i++){
        //If the category and value matches, return true
        if (strcmp(questions[i].category, category) == 0 && (questions[i].value = value) && (questions[i].answered == true) ){
            return true;
        }
    }
    return false;
}
