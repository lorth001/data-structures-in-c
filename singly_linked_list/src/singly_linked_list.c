#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"


void print_list(Node* head) {
	Node *temp = head;
	if (temp == NULL) printf("The list is empty\n");
	printf("\n head\n  |\n  ");
	while (temp != NULL) {
		printf("%i --> ", temp->value);
		temp = temp->next;
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
	Node *temp = *head;
	if (node_to_delete == temp) {
		// update where head points if deleting first node
		*head = node_to_delete->next;
		free(temp);
		return;
	}
	else {
		while (temp != NULL) {
			if (temp->next == node_to_delete) {
				temp->next = node_to_delete->next;
				free(node_to_delete);
				return;
			}
			temp = temp->next;
		}
	}
	return;
}

Node *delete_list(Node *head) {
	Node *temp = head;
	Node *next_node = NULL;
	while (temp != NULL) {
		next_node = temp->next;
		free(temp);
		temp = next_node;
	}
	return temp;
}

Node *insert_at_beginning(Node **head, Node *node_to_insert) {
	node_to_insert->next = *head;
	*head = node_to_insert;
	return node_to_insert;
}

void insert_at_end(Node *head, Node *new_node) {
	Node *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;
}

Node *insert_after_node(Node *node_to_insert_after, Node *new_node) {
	new_node->next = node_to_insert_after->next;
	node_to_insert_after->next = new_node;
	return new_node;	
}

Node *get_node_by_value(Node* head, int value) {
	Node *temp = head;
	while (temp != NULL) {
		if (temp->value == value) return temp;
		temp = temp->next;
	}
	return NULL;
}
