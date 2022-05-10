#include <stdio.h>
#include <stdlib.h>

// each node contains a value and a pointer to the next node
struct Node {
	int value;
	struct Node* next;
};

// print the list - takes O(n) time
void print_list(struct Node* head) {
	struct Node *temporary = head;
	
	while (temporary != NULL) {
		printf("%i -> ", temporary->value);
		temporary = temporary->next;
	}
	printf("\n");
	return;
}

// create a new node - takes O(1) time
struct Node *create_node(int value) {
	struct Node *result = malloc(sizeof(struct Node));
	result->value = value;
	result->next = NULL;

	return result;
}

// delete the node specified by value - takes O(n) time
void delete_node(struct Node **head, struct Node *node_to_delete) {
	struct Node *temporary = *head;
	
	// if the first node is being deleted, update where the head points to
	if (node_to_delete == temporary) {
		*head = node_to_delete->next;
		free(temporary);
		return;
	}
	else {
		while (temporary != NULL) {
			if (temporary->next == node_to_delete) {
				temporary->next = node_to_delete->next;
				free(node_to_delete);
				return;
			}
			temporary = temporary->next;
		}
	}
	return;
}

// insert a new node at the head - takes O(1) time
struct Node *insert_at_head(struct Node **head, struct Node *node_to_insert) {
	node_to_insert->next = *head;
	*head = node_to_insert;

	return node_to_insert;
}

// insert a new node after node specified by pointer - takes O(1) time
struct Node *insert_after_node(struct Node *node_to_insert_after, struct Node *new_node) {
	new_node->next = node_to_insert_after->next;
	node_to_insert_after->next = new_node;

	return new_node;	
}

// find a node by value - takes O(n) time
struct Node *get_node_with_value(struct Node* head, int value) {
	struct Node *temporary = head;

	while (temporary != NULL) {
		if (temporary->value == value) return temporary;
		temporary = temporary->next;
	}

	return NULL;
}

// find the node at specified position - takes O(n) time
struct Node *get_node_at_position(struct Node* head, int position) {
	struct Node *temporary = head;

	for (int i = 0; i <= position && temporary != NULL; i++) {
		if (i == position) return temporary;
		temporary = temporary->next;
	}

	return NULL;
}

int main() {
	struct Node *head = NULL;
	struct Node *tmp;

	printf("\nCreate initial list:\n");
	for (int i = 0; i < 25; i++) {
		tmp = create_node(i);
		insert_at_head(&head, tmp);
	}
	print_list(head);

	int value = 10;
	printf("\nFind node with value = %i:\n", value);
	tmp = get_node_with_value(head, value);
	if (tmp == NULL) {
		printf("Not found\n");
	}
	else {
		printf("Found!\n");
	}
	
	value = 100;
	printf("\nFind node with value = %i:\n", value);
	tmp = get_node_with_value(head, value);
	if (tmp == NULL) {
		printf("Not found\n");
	}
	else {
		printf("Found!\n");
	}

	int position = 10;
	printf("\nFind node at position %i:\n", position);
	tmp = get_node_at_position(head, position);
	if (tmp == NULL) {
		printf("Not found\n");
	}
	else {
		printf("Found! Value = %i\n", tmp->value);
	}

	position = 100;
	printf("\nFind node at position %i:\n", position);
	tmp = get_node_at_position(head, position);
	if (tmp == NULL) {
		printf("Not found\n");
	}
	else {
		printf("Found! Value = %i\n", tmp->value);
	}

	value = 100;
	printf("\nInsert a new node with value %i at the head:\n", value);
	tmp = insert_at_head(&head, create_node(100));
	print_list(head);

	value = 90;
	int after = 11;
	printf("\nInsert a new node with value %i after the %ith node:\n", value, after);
	tmp = insert_after_node(get_node_at_position(head, after), create_node(value));
	print_list(head);

	value = 5;
	printf("\nDelete node with the value %i:\n", value);
	tmp = get_node_with_value(head, value);
	delete_node(&head, tmp);
	print_list(head);

	return 0;
}
