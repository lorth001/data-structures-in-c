#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

void print_list(Node* head) {
	Node *temporary = head;
	while (temporary != NULL) {
		printf("%i -> ", temporary->value);
		temporary = temporary->next;
	}
	printf("\n");
	return;
}

Node *create_node(int value) {
	Node *result = malloc(sizeof(Node));
	result->value = value;
	result->next = NULL;
	return result;
}

void delete_node(Node **head, Node *node_to_delete) {
	Node *temporary = *head;
	if (node_to_delete == temporary) {
		// update where head points if deleting first node
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

Node *insert_at_head(Node **head, Node *node_to_insert) {
	node_to_insert->next = *head;
	*head = node_to_insert;
	return node_to_insert;
}

Node *insert_after_node(Node *node_to_insert_after, Node *new_node) {
	new_node->next = node_to_insert_after->next;
	node_to_insert_after->next = new_node;
	return new_node;	
}

Node *get_node_by_value(Node* head, int value) {
	Node *temporary = head;
	while (temporary != NULL) {
		if (temporary->value == value) return temporary;
		temporary = temporary->next;
	}
	return NULL;
}

Node *get_node_by_position(Node* head, int position) {
	Node *temporary = head;
	for (int i = 0; i <= position && temporary != NULL; i++) {
		if (i == position) return temporary;
		temporary = temporary->next;
	}
	return NULL;
}

int main() {
	Node *head = NULL;
	Node *tmp;

	printf("\nCreate initial list:\n");
	for (int i = 0; i < 25; i++) {
		tmp = create_node(i);
		insert_at_head(&head, tmp);
	}
	print_list(head);

	int value = 10;
	printf("\nFind node with value = %i:\n", value);
	tmp = get_node_by_value(head, value);
	if (tmp == NULL) {
		printf("Not found\n");
	}
	else {
		printf("Found!\n");
	}
	
	value = 100;
	printf("\nFind node with value = %i:\n", value);
	tmp = get_node_by_value(head, value);
	if (tmp == NULL) {
		printf("Not found\n");
	}
	else {
		printf("Found!\n");
	}

	int position = 10;
	printf("\nFind node at position %i:\n", position);
	tmp = get_node_by_position(head, position);
	if (tmp == NULL) {
		printf("Not found\n");
	}
	else {
		printf("Found! Value = %i\n", tmp->value);
	}

	position = 100;
	printf("\nFind node at position %i:\n", position);
	tmp = get_node_by_position(head, position);
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
	tmp = insert_after_node(get_node_by_position(head, after), create_node(value));
	print_list(head);

	value = 5;
	printf("\nDelete node with the value %i:\n", value);
	tmp = get_node_by_value(head, value);
	delete_node(&head, tmp);
	print_list(head);

	return 0;
}
