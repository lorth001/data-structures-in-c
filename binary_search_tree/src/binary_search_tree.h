#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H


// Tree nodes
typedef struct Node {
	int value;
	struct Node *left;
	struct Node *right;	
} Node;

// Create a Node 
Node *create_node(int value);

// Insert a value into the tree 
Node *insert_value(Node **root, int value);

// Utility function for printing the tree
void print_util(struct Node *root, int space);

// Print the tree
void print_tree(struct Node *root);

// Determine if the tree contains the given value
Node *find_value(Node *root, int value);

// Delete the Node with the given value
Node *delete_value(Node **root, int value);


#endif
