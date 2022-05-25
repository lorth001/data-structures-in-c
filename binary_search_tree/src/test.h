#ifndef TEST_H
#define TEST_H

#include "binary_search_tree.h"


// Gets user input as dynamic char array and returns its pointer (needs to be freed)
char *user_input();

// Gets an int from the user
int get_int_from_user();

// Initialize BST from a file
Node *init_bst_from_file(Node *root, char *filename);

// Initialize BST with random values - the size of the tree and the range of 
// values are specified by the user
Node *init_random_bst(Node *root, int min, int max, int size);

// The program's UI that handles the menu and logic
void prompt(Node *root);


#endif
