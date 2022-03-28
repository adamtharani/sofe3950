//
//  main.c
//  tutorial_5
//
//  Created by Adam Tharani on 2022-03-25.
//
#define _XOPEN_SOURCE 700
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/stat.h>

void question1(void);
void question2(void);
void question3(void);
void writeFile(char *body, char *fileName, char *writeMode);
void readFile(char *fileName);
struct factorialInput {
    int number;
    int index ;
};
void factorial(struct factorialInput input);


int main(int argc, const char * argv[]) {
//    question1();
//    question2();
//    question3();
    return 0;
}

void question1(void) {
    pid_t child_a, child_b;
    
    child_a = fork();
    
    if (child_a == 0) {
        /* Child A code */
        sleep(1);
        printf("I am child 1 \n");
        readFile("child1.txt");
        
    } else {
        child_b = fork();
        
        if (child_b == 0) {
            /* Child B code */
            sleep(1);
            printf("I am child 2 \n");
            readFile("child2.txt");
        } else {
            /* Parent Code */
            writeFile("child 1", "child1.txt", "w");
            writeFile("child 2", "child2.txt", "w");
        }
    }
}

void question2(void) {
    pid_t child_a;
    int child_a_status;
    
    child_a = fork();
    
    if (child_a == 0) {
        /* Child A code */
        sleep(1);
        printf("Child process\n");
    } else {
        /* Parent Code */
        wait(&child_a_status);
        printf("Parent process\n");
        printf("Exit status: %d\n", WEXITSTATUS(child_a_status));
    }
}

int moving_sum[5] = {0, 0, 0, 0, 0};

void question3(void) {
    for (int counter = 0; counter < 5; counter++) {
        printf("Please enter a number: ");
        scanf("%d", &moving_sum[counter]);
        printf("You entered %d\n", moving_sum[counter]);
        
        struct factorialInput input;
        input.index = counter;
        input.number = moving_sum[counter];
        
        factorial(input);
    }
    
}

void writeFile(char *body, char *fileName, char *fileMode) {
    FILE *fp;
    
    // Open file to in given mode the text in
    fp = fopen(fileName, fileMode);
    if (fp == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    fprintf(fp, "%s", body);
    
    //Close file
    fclose(fp);
}

void readFile(char *fileName) {
    FILE *fp;
    struct stat sb;
    stat(fileName, &sb);
    char *file_contents = malloc(sb.st_size);
    
    // Open file to write the text in
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    while (fscanf(fp, "%[^\n] ", file_contents) != EOF) {
        printf("Value of file %s is %s\n", fileName, file_contents);
    }
}

void factorial(struct factorialInput input) {
    int factorial_value = 1;
    for (int counter = 1; counter <= input.number; counter++) {
        factorial_value *= counter;
    }
    printf("The factorial of %d is %d\n", input.number , factorial_value);
}

