#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list.h"


char *user_input() {
	int bytes = 0;
	int capacity = 50;
	char *buf = malloc(capacity);
	char c;

	while ((c = fgetc(stdin)) != '\n') {
		bytes++;
		buf = (bytes+1 >= capacity) ? realloc(buf, capacity *= 2) : buf;
		buf[bytes-1] = c;
	}

	buf[bytes] = 0;
	return buf;
}

int get_num_from_usr() {
	char *str = user_input();
	int num = atoi(str);
	free(str);
	str = NULL;
	return num;
}

Node *init_list_from_file(Node *head, char *filename) {
	FILE * fin = fopen(filename, "r");

	if (fin == NULL) {
		printf("Could not open file\n");
		perror("fopen");
		exit(0);
	}

	const int LINE_SIZE=12;
	char line[LINE_SIZE];

	while (fgets(line, LINE_SIZE, fin) != NULL) {
		Node *value = create_node(atoi(line));
		insert_at_head(&head, value);
	}
	fclose(fin);
	return head;
}

void prompt(Node *head, int option) {
	Node *element = NULL;
	if (head == NULL) {
		printf("\n1) Create a new list from the console\n");
		printf("2) Create a new list from a file\n");
		printf("> ");

		switch (get_num_from_usr()) {
			case 1:
				printf("You selected option 1\n");
				break;

			case 2:
				printf("Filename: ");
				char *filename = user_input();
				head = init_list_from_file(head, filename);
				free(filename);
				filename = NULL;
				prompt(head, 0);

			default:
				printf("\nInvalid entry - please try again\n");
				prompt(NULL, 0);
		}
	}
	else {
		printf("\n----------------------------------------\n");
		printf("1) Print the list\n");
		printf("2) Insert at the beginning\n");
		printf("3) Insert at the end\n");
		printf("4) Insert after element\n");
		printf("5) Delete\n");
		printf("6) Search\n");
		printf("> ");

		switch (get_num_from_usr()) {
			case 1:
				printf("\nLINKED-LIST:\n");
				print_list(head);
				prompt(head, 0);

			case 2:
				printf("Value: ");
				head = insert_at_head(&head, create_node(get_num_from_usr()));
				prompt(head, 0);

			case 3:
				printf("Value: ");
				insert_at_tail(head, create_node(get_num_from_usr()));
				prompt(head, 0);

			case 4:
				printf("Element to insert after: ");
				element = get_node_by_value(head, get_num_from_usr());
				if (element == NULL) {
					printf("Element not found\n");
					prompt(head, 0);
				}
				printf("Value: ");
				insert_after_node(element, create_node(get_num_from_usr()));
				prompt(head, 0);

			case 5:
				printf("Element to delete: ");
				element = get_node_by_value(head, get_num_from_usr());
				if (element == NULL) {
					printf("Element not found\n");
					prompt(head, 0);
				}
				delete_node(&head, element);
				printf("Element deleted\n");
				prompt(head, 0);

			case 6:
				printf("Element to find: ");
				element = get_node_by_value(head, get_num_from_usr());
				if (element == NULL) {
					printf("Element not found\n");
					prompt(head, 0);
				}
				printf("Element found!\n");
				prompt(head, 0);

			default:
				printf("\nInvalid entry - please try again\n");
				prompt(head, 0);
		}
	}
}

int main() {
	printf("********** WELCOME **********\n");
	printf("Please select an option:\n");
	prompt(NULL, 0);

	return 0;
}
