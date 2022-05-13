#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


// Each list item is represented as a Node
typedef struct Node {
	int value;
	struct Node* next;
} Node;

// Print the complete list
void print_list(Node* head);

// Create Node with value
Node *create_node(int value);

// Delete Node by value (must provide ref to the head)
void delete_node(Node **head, Node *node_to_delete);

// Delete entire list
Node *delete_list(Node *head);

// Insert Node at the list head (must provide ref to the head)
Node *insert_at_head(Node **head, Node *node_to_insert);

// Insert Node at the list tail
void insert_at_tail(Node *head, Node *new_node);

// Insert Node after another Node
Node *insert_after_node(Node *node_to_insert_after, Node *new_node);

// Get Node by value
Node *get_node_by_value(Node* head, int value);

// Get Node by position
Node *get_node_by_position(Node* head, int position);


#endif
