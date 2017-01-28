#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


int main(int argc, char** argv) {
    // Buffer for input.
    char input_buffer[512];
    // Pointer to the input file.
    FILE *input;
    // Check for correct number of arguments.
    if (argc == 1 || argc > 2){
        printf("Incorrect number of arguments. Please supply a single filename argument.\n");
        exit(0);
    }else {
        printf("Attempting to open %s\n",argv[1]);
        // Open the file in read mode.
        input = fopen(argv[1],"r");
        // Check if file open was successful
        if (input == NULL){
            printf("Failed to open file \'%s\', please check that the file exists.\n",argv[1]);
            exit(0);
        }else{
            printf("Successfully opened file \'%s\'.\n",argv[1]);
        }
    }

    // Create Head node for binary tree.
    struct node* head = malloc(sizeof(struct node));
    // We read the first line and use this information to create the head node.
    if(fscanf(input,"%s",input_buffer) != EOF){
        head->word = malloc(sizeof(input_buffer));
        strcpy(head->word,input_buffer);
        head->count = 1;
        head->left_child = NULL;
        head->right_child = NULL;
    }
    // Loop through the rest of the file.
    while(fscanf(input,"%s",input_buffer) != EOF){
        printf("%s\n",input_buffer);
        searchForWord(input_buffer,head);
    }

    printf("Starting In-Order Traversal.\n");
    in_order_traverse(head);

    // Memory cleanup.
    delete_tree(head);
    free(head);

    // Close file.
    fclose(input);
}
int searchForWord(char* word, struct node* search_node){
    // This is the word we want.
    if(strcmp(word,search_node->word) == 0){
        search_node->count = search_node->count+1;
        printf("Word \'%s\' already exists",word);
        printf(", the count is now %d\n",search_node->count);
    }
    // Word is less, so go left.
    else if(strcmp(word,search_node->word) < 0){
        if (search_node->left_child == NULL){
            // Allocate space for the node structure.
            search_node->left_child = malloc(sizeof(struct node));
            // Allocate space for the char*
            search_node->left_child->word = malloc(sizeof(word));
            // Copy the word into the char*
            strcpy(search_node->left_child->word,word);
            // Set count to 1.
            search_node->left_child->count = 1;

            // Set both children to NULL
            search_node->left_child->left_child = NULL;
            search_node->left_child->right_child = NULL;
            printf("Added new word \'%s\'.\n",word);
        }else {
            searchForWord(word, search_node->left_child);
        }
    }
    // Word is greater, so go right.
    else {
        if(search_node->right_child == NULL){
            // Allocate space for node structure
            search_node->right_child = malloc(sizeof(struct node));
            // Allocate space for char*
            search_node->right_child->word = malloc(sizeof(word));
            // Copy word into the char*
            strcpy(search_node->right_child->word,word);
            // Set count to 1.
            search_node->right_child->count = 1;

            // Set both children to NULL
            search_node->right_child->left_child = NULL;
            search_node->right_child->right_child = NULL;
            printf("Added new word \'%s\'.\n",word);
        }else {
            searchForWord(word, search_node->right_child);
        }
    }
    return 0;
}
void in_order_traverse(struct node* start){
    // If node is NULL, we're done in this branch, just return.
    if(start == NULL){
        return;
    }else{
        // Recursive transit of left children.
        in_order_traverse(start->left_child);
        // Print each word and its count.
        printf("Word: \'%s\'\n", start->word);
        printf("Count: %d\n",start->count);
        // Recursive transit of right children.
        in_order_traverse(start->right_child);
    }
}

void delete_tree(struct node* start){
    if(start != NULL){
        if(start->left_child == NULL && start->right_child == NULL){
            return;
        }else{
            delete_tree(start->left_child);
            if(start->left_child != NULL) {
                printf("Deleting \'%s\'.\n",start->left_child->word);
                free(start->left_child->word);
                free(start->left_child);
            }
            delete_tree(start->right_child);
            if(start->right_child != NULL) {
                printf("Deleting \'%s\'.\n",start->right_child->word);
                free(start->right_child->word);
                free(start->right_child);
            }
        }
    }else{
        return;
    }
}