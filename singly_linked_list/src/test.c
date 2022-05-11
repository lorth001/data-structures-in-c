#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"


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
