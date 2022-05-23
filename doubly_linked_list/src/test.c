#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "test.h"


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

int get_int_from_user() {
	char *str = user_input();
	int num = atoi(str);

	free(str);
	str = NULL;

	return num;
}

Node *init_list_from_file(Node *head, char *filename) {
	FILE * fin = fopen(filename, "r");

	if (fin == NULL) {
		printf("Could not open file...\n");
		perror("fopen");
		return NULL;
	}

	const int LINE_SIZE=12;
	char line[LINE_SIZE];

	while (fgets(line, LINE_SIZE, fin) != NULL) {
		Node *value = create_node(atoi(line));
		insert_at_beginning(&head, value);
	}

	fclose(fin);

	return head;
}

Node *init_random_list(Node *head, int min, int max, int size) {
	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		int random_value = min + rand() / (RAND_MAX / (max - min + 1) + 1);
		head = insert_at_beginning(&head, create_node(random_value));
	}

	return head;
}

void prompt(Node *head) {
	if (head == NULL) {
		printf("\n********** WELCOME **********\n");
		printf("Please select an option:\n");
		printf("\n1) Initialize a new list from the console\n");
		printf("2) Initialize a new list from a file\n");
		printf("3) Exit\n");
		printf("> ");

		switch (get_int_from_user()) {
			case 1:
				printf("List size: ");
				int size = get_int_from_user();
				printf("Minimum value: ");
				int min = get_int_from_user();
				printf("Maximum value: ");
				head = init_random_list(head, min, get_int_from_user(), size);
				prompt(head);
				break;

			case 2:
				printf("Filename: ");
				char *filename = user_input();
				head = init_list_from_file(head, filename);
				free(filename);
				filename = NULL;
				prompt(head);

			case 3:
				printf("Goodbye!\n");
				exit(0);

			default:
				printf("\nInvalid entry - please try again\n");
				prompt(NULL);
		}
	}
	else {
		Node *element = NULL;
		printf("\n----------------------------------------\n");
		printf("1) Print the list\n");
		printf("2) Insert at the beginning\n");
		printf("3) Insert at the end\n");
		printf("4) Insert after element\n");
		printf("5) Delete\n");
		printf("6) Search\n");
		printf("7) Delete the list\n");
		printf("8) Exit\n");
		printf("> ");

		switch (get_int_from_user()) {
			case 1:
				printf("\nLINKED-LIST:\n");
				print_list(head);
				prompt(head);

			case 2:
				printf("Value: ");
				head = insert_at_beginning(&head, create_node(get_int_from_user()));
				prompt(head);

			case 3:
				printf("Value: ");
				insert_at_end(head, create_node(get_int_from_user()));
				prompt(head);

			case 4:
				printf("Element to insert after: ");
				element = get_node_by_value(head, get_int_from_user());
				if (element == NULL) {
					printf("Element not found\n");
					prompt(head);
				}
				printf("Value: ");
				insert_after_node(element, create_node(get_int_from_user()));
				prompt(head);

			case 5:
				printf("Element to delete: ");
				element = get_node_by_value(head, get_int_from_user());
				if (element == NULL) {
					printf("Element not found\n");
					prompt(head);
				}
				delete_node(&head, element);
				printf("Element deleted\n");
				prompt(head);

			case 6:
				printf("Element to find: ");
				element = get_node_by_value(head, get_int_from_user());
				if (element == NULL) {
					printf("Element not found\n");
					prompt(head);
				}
				printf("Element found!\n");
				prompt(head);

			case 7:
				head = delete_list(head);
				printf("List deleted!\n");
				prompt(head);

			case 8:
				head = delete_list(head);
				printf("Goodbye!\n");
				exit(0);

			default:
				printf("\nInvalid entry - please try again\n");
				prompt(head);
		}
	}
}
