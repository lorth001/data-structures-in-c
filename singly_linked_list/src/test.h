#ifndef TEST_H
#define TEST_H

#include "singly_linked_list.h"


// Gets user input as dynamic char array and returns its pointer (needs to be freed)
char *user_input();

// Gets an int from the user
int get_int_from_user();

// Initialize linked list from a file
Node *init_list_from_file(Node *head, char *filename);

// Initialize a linked list with random values - the size of the list and the range of 
// values are specified by the user
Node *init_random_list(Node *head, int min, int max, int size);

// The program's UI that handles the menu and logic
void prompt(Node *head);


#endif
