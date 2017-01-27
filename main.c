#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * A struct definition for a single node in our binary tree.
 */
struct node {
    char* word;
    int count;
    struct node* left_child;
    struct node* right_child;
};

int main(int argc, char** argv) {
    // Check for correct number of arguments.
    if (argc == 1 || argc > 2){
        printf("Incorrect number of arguments. Please supply a single filename argument.\n");
        exit(0);
    }else {
        printf("Attempting to open %s\n",argv[1]);
        // Pointer to the input file
        FILE *input;
        // Open the file in read mode.
        input = fopen(argv[1],"r");
        // Check if file open was successful
        if (input == NULL){
            printf("Failed to open file \'%s\', please check that the file exists.\n",argv[1]);
            exit(0);
        }
    }

    // Create Head node for binary tree.
    struct node* head = malloc(sizeof(struct node));



}
