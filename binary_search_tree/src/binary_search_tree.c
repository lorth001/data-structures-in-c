#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"


Node *create_node(int value) {
	Node *new_node = malloc(sizeof(Node));
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

bool insert_value(Node **root, int value) {
	if (*root == NULL) {
		// tree is empty - create new node
		*root = create_node(value);
		return true;
	}
	else if (value == (*root)->value) {
		// tree already contains value - do nothing
		return false;
	}
	else if (value < (*root)->value) {
		// recursive call on left subtree
		return insert_value(&(*root)->left, value);
	}
	else {
		// recursive call on right subtree
		return insert_value(&(*root)->right, value);
	}
}

bool find_value(Node *root, int value) {
	if (root == NULL) {
		// could not find value
		return false;
	}
	else if (value == root->value) {
		// found value
		return true;
	}
	else if (value < root->value) {
		// recursive call on left subtree
		return find_value(root->left, value);
	}
	else {
		// recursive call on right subtree
		return find_value(root->right, value);
	}
}

Node *delete_value(Node **root, int value) {
	if ((*root) == NULL) {
		// value doesn't exist
		return NULL;
	}
	else if (value < (*root)->value) {
		// recursive call on left subtree
		(*root)->left = delete_value(&(*root)->left, value);
	}
	else if (value > (*root)->value) {
		// recursive call on right subtree
		(*root)->right = delete_value(&(*root)->right, value);
	}
	else {
		// found the node to delete
		// case 1: no children nodes
		if ((*root)->left == NULL && (*root)->right == NULL) {
			free(*root);
			*root = NULL;
		}
		// case 2: one left node
		else if ((*root)->left == NULL) {
			*root = (*root)->right;
			free((*root)->right);
			(*root)->right = NULL;
		}
		// case 3: one right node
		else if ((*root)->right == NULL) {
			*root = (*root)->left;
			free((*root)->left);
			(*root)->left = NULL;
		}
		// case 4: two children nodes
		else {
			// get the inorder predecessor
			Node *temp = (*root)->left;
			while (temp->right != NULL) {
				temp = temp->right;
			}
			// swap values and delete inorder predecessor with a recursive call
			(*root)->value = temp->value;
			(*root)->left = delete_value(&(*root)->left, temp->value);
		}
	}
	// always return a pointer to the root
	return *root;
}

void print_util(struct Node *root, int space) {
    if (root == NULL)
        return;
 
    // increase distance between levels
    space += SPACES;
 
    // process right child first
    print_util(root->right, space);
 
    // print current node after space
	printf("\n");
    for (int i = SPACES; i < space; i++) {
		//printf(" ");
		if (i < space-SPACES) {
			printf(" ");
		}
		else if (i > space-SPACES) {
			printf("-");
		}
		else {
			printf("+");
		}
	}
    printf("%d\n", root->value);
 
    // process left child
    print_util(root->left, space);
}
 
void print_tree(struct Node *root) {
   print_util(root, 0);
   printf("\n");
}


int main() {
	Node *root = NULL;

	insert_value(&root, 15);
	insert_value(&root, 100);
	insert_value(&root, 10);
	insert_value(&root, 17);
	insert_value(&root, 20);
	insert_value(&root, 2);
	insert_value(&root, 1);
	insert_value(&root, 8);
	insert_value(&root, 1);
	insert_value(&root, 11);

	printf("%d -> %d\n", 15, find_value(root, 15));
	printf("%d -> %d\n", 10, find_value(root, 10));
	printf("%d -> %d\n", 17, find_value(root, 17));
	printf("%d -> %d\n", 90, find_value(root, 90));
	printf("%d -> %d\n", 100, find_value(root, 100));
	printf("%d -> %d\n", 1, find_value(root, 1));

	print_tree(root);

	delete_value(&root, 15);
	delete_value(&root, 1);
	delete_value(&root, 100);
	delete_value(&root, 11);
	delete_value(&root, 1000);
	print_tree(root);

	printf("%d -> %d\n", 1, find_value(root, 1));
	return 0;
}
