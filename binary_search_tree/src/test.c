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

Node *init_bst_from_file(Node *root, char *filename) {
	FILE * fin = fopen(filename, "r");

	if (fin == NULL) {
		printf("Could not open file...\n");
		perror("fopen");
		return NULL;
	}

	const int LINE_SIZE=12;
	char line[LINE_SIZE];
	
	printf("\nThe following values were inserted in this order:\n");
	while (fgets(line, LINE_SIZE, fin) != NULL) {
		Node *new_node = insert_value(&root, atoi(line));
		if (new_node != NULL) {
			printf("%d, ", atoi(line));
		}
	}
	

	fclose(fin);
	return root;
}

Node *init_random_bst(Node *root, int min, int max, int size) {
	srand(time(NULL));

	printf("\nThe following values were inserted in this order:\n");
	for (int i = 0; i < size; i++) {
		int random_value = min + rand() / (RAND_MAX / (max - min + 1) + 1);
		Node *new_node = insert_value(&root, random_value);
		if (new_node != NULL) {
			printf("%d, ", random_value);
		}
	}

	return root;
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
				root = init_random_bst(root, min, get_int_from_user(), size);
				prompt(root);
				break;

			case 2:
				printf("Filename: ");
				char *filename = user_input();
				root = init_bst_from_file(root, filename);
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
		Node *element = NULL;
		printf("\n----------------------------------------\n");
		printf("1) Print the BST\n");
		printf("2) Insert new value\n");
		printf("3) Delete value\n");
		printf("4) Search\n");
		printf("5) Delete the BST\n");
		printf("6) Exit\n");
		printf("> ");

		switch (get_int_from_user()) {
			case 1:
				printf("\nBINARY SEARCH TREE (BST):\n");
				print_tree(root);
				prompt(root);

			case 2:
				printf("Value: ");
				element = insert_value(&root, get_int_from_user());
				if (element == NULL) {
					printf("Value already exists\n");
				}
				prompt(root);

			case 3:
				printf("Value to delete: ");
				root = delete_value(root, get_int_from_user());
				prompt(root);

			case 4:
				printf("Value to find: ");
				element = find_value(root, get_int_from_user());
				if (element == NULL) {
					printf("Value not found\n");
					prompt(root);
				}
				printf("Value found!\n");
				prompt(root);

			case 5:
				root = delete_tree(root);
				printf("Tree deleted!\n");
				prompt(root);

			case 6:
				root = delete_tree(root);
				printf("Goodbye!\n");
				exit(0);

			default:
				printf("\nInvalid entry - please try again\n");
				prompt(root);
		}
	}
}
