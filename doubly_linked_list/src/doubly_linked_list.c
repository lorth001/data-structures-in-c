#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"


void print_list(Node* head) {
	Node *temp = head;
	if (temp == NULL) printf("The list is empty\n");
	printf("\n head\n  |\n  ");
	while (temp != NULL) {
		printf("%i <--> ", temp->value);
		temp = temp->next;
	}
	printf("NULL\n");
	return;
}

Node *create_node(int value) {
	Node *result = malloc(sizeof(Node));
	result->value = value;
	result->next = NULL;
	result->prev = NULL;
	return result;
}

void delete_node(Node **head, Node *node_to_delete) {
	Node *temp = *head;
	if (node_to_delete == temp) {
		// update where head points if deleting first node
		*head = node_to_delete->next;
		(*head)->prev = NULL;
		return;
	}
	else {
		node_to_delete->prev->next = node_to_delete->next;
		if (node_to_delete->next != NULL) {
			node_to_delete->next->prev = node_to_delete->prev;
		}
	}
	node_to_delete->next = NULL;
	node_to_delete->prev = NULL;
	free(node_to_delete);
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
	node_to_insert->prev = NULL;
	if (*head != NULL) {
		(*head)->prev = node_to_insert;
	}
	*head = node_to_insert;
	return node_to_insert;
}

void insert_at_end(Node *head, Node *new_node) {
	Node *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	new_node->prev = temp;
	temp->next = new_node;
}

Node *insert_after_node(Node *node_to_insert_after, Node *new_node) {
	new_node->next = node_to_insert_after->next;
	if (new_node->next != NULL) {
		new_node->next->prev = new_node;
	}
	new_node->prev = node_to_insert_after;
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
