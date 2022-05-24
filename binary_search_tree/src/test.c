#include <stdbool.h>
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

bool init_bst_from_file(Node *root, char *filename) {
	FILE * fin = fopen(filename, "r");

	if (fin == NULL) {
		printf("Could not open file...\n");
		perror("fopen");
		return NULL;
	}

	const int LINE_SIZE=12;
	char line[LINE_SIZE];

	bool success = true;
	while (fgets(line, LINE_SIZE, fin) != NULL) {
		success &= insert_value(&root, atoi(line));
	}

	fclose(fin);
	return success;
}

bool init_random_bst(Node *root, int min, int max, int size) {
	srand(time(NULL));

	bool success = true;
	for (int i = 0; i < size; i++) {
		int random_value = min + rand() / (RAND_MAX / (max - min + 1) + 1);
		success &= insert_value(&root, random_value);
	}

	return success;
}

void prompt(Node *root) {
	if (root == NULL) {
		printf("\n********** WELCOME **********\n");
		printf("Please select an option:\n");
		printf("\n1) Initialize a new BST from the console\n");
		printf("2) Initialize a new BST from a file\n");
		printf("3) Exit\n");
		printf("> ");

		switch (get_int_from_user()) {
			case 1:
				printf("Number of nodes: ");
				int size = get_int_from_user();
				printf("Minimum value: ");
				int min = get_int_from_user();
				printf("Maximum value: ");
				init_random_bst(root, min, get_int_from_user(), size);
				prompt(root);
				break;

			case 2:
				printf("Filename: ");
				char *filename = user_input();
				init_bst_from_file(root, filename);
				free(filename);
				filename = NULL;
				prompt(root);

			case 3:
				printf("Goodbye!\n");
				exit(0);

			default:
				printf("\nInvalid entry - please try again\n");
				prompt(NULL);
		}
	}
	else {
		/* LEFT OFF HERE */
		Node *element = NULL;
		printf("\n----------------------------------------\n");
		printf("1) Print the BST\n");
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
				print_list(root);
				prompt(root);

			case 2:
				printf("Value: ");
				root = insert_at_beginning(&root, create_node(get_int_from_user()));
				prompt(root);

			case 3:
				printf("Value: ");
				insert_at_end(root, create_node(get_int_from_user()));
				prompt(root);

			case 4:
				printf("Element to insert after: ");
				element = get_node_by_value(root, get_int_from_user());
				if (element == NULL) {
					printf("Element not found\n");
					prompt(root);
				}
				printf("Value: ");
				insert_after_node(element, create_node(get_int_from_user()));
				prompt(root);

			case 5:
				printf("Element to delete: ");
				element = get_node_by_value(root, get_int_from_user());
				if (element == NULL) {
					printf("Element not found\n");
					prompt(root);
				}
				delete_node(&root, element);
				printf("Element deleted\n");
				prompt(root);

			case 6:
				printf("Element to find: ");
				element = get_node_by_value(root, get_int_from_user());
				if (element == NULL) {
					printf("Element not found\n");
					prompt(root);
				}
				printf("Element found!\n");
				prompt(root);

			case 7:
				root = delete_list(root);
				printf("List deleted!\n");
				prompt(root);

			case 8:
				root = delete_list(root);
				printf("Goodbye!\n");
				exit(0);

			default:
				printf("\nInvalid entry - please try again\n");
				prompt(root);
		}
	}
}
