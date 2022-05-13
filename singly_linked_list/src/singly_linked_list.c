#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"


void print_list(Node* head) {
	Node *temporary = head;
	if (temporary == NULL) printf("The list is empty\n");
	printf("\n head\n  |\n  ");
	while (temporary != NULL) {
		printf("%i --> ", temporary->value);
		temporary = temporary->next;
	}
	printf("NULL\n");
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

Node *delete_list(Node *head) {
	Node *temporary = head;
	Node *next_node = NULL;
	while (temporary != NULL) {
		next_node = temporary->next;
		free(temporary);
		temporary = next_node;
	}
	return temporary;
}

Node *insert_at_head(Node **head, Node *node_to_insert) {
	node_to_insert->next = *head;
	*head = node_to_insert;
	return node_to_insert;
}

void insert_at_tail(Node *head, Node *new_node) {
	Node *temporary = head;
	while (temporary->next != NULL) {
		temporary = temporary->next;
	}
	temporary->next = new_node;
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
