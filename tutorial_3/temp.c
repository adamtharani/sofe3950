#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



bool valid_answer(char *category, int value, char *answer)
{
    /*
    char *question = "questions";
    char *answer = "answer";
    int temp = 200;

    for (int i=0; i<12; i++){
        //compare the question and value 
        if ( queset ){
            if (strcasecmp(answer, answer) == 0)
                printf("Correct");
                return true;
        }
        else
            printf("Incorrect");
            return false;
    }*/
    return true;
}

void tokenize(char *input, char **tokens){

    char *token1 = strtok(input, " ");
    token1 = strtok(input, " ");

    for(int i = 0; token1 != NULL; i++){
        strcpy(tokens[i], token1);
        token1 = strtok(NULL, " ");
    }       
}

int main(int argc, char *argv[])
{
    
    char userInput[256] = {0};
    char **token;

    printf("Enter the answer: ");
    scanf("%s ", userInput);

    char *category;
    int value;
    char *answer;
    
    tokenize(userInput, token);                               //extracts answer from response
    bool correct = valid_answer(category,value,token[2]);
    
    if(correct){
        printf("Correct! You may now choose another question.\n\n");
            //players[i].score += value;
            //i--;
        }
        
        else{
            printf("Unfortunately, that is incorrect, or you forgot to say \"What is/Who is\".\n\n");
        }

    //valid_answer(category, value, answer);

}