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

Node *insert_value(Node **root, int value) {
	if (*root == NULL) {
		// tree is empty - create new node
		*root = create_node(value);
		return *root;
	}
	else if (value == (*root)->value) {
		// tree already contains value - do nothing
		return NULL;
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

Node *find_value(Node *root, int value) {
	if (root == NULL) {
		// could not find value
		return NULL;
	}
	else if (value == root->value) {
		// found value
		return root;
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

Node *delete_value(Node *root, int value) {
	if (root == NULL) {
		return NULL;
	}
	else if (value < root->value) {
		// recursive call on left subtree
		root->left = delete_value(root->left, value);
	}
	else if (value > root->value) {
		// recursive call on right subtree
		root->right = delete_value(root->right, value);
	}
	else {
		// found the node to delete
		if (root->left == NULL) {
			Node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			Node *temp = root->left;
			free(root);
			return temp;
		}
		// case 4: two children nodes
		else {
			// get the inorder predecessor
			Node *temp = root->left;
			while (temp->right != NULL) {
				temp = temp->right;
			}
			// swap values and delete inorder predecessor with a recursive call
			root->value = temp->value;
			root->left = delete_value(root->left, temp->value);
		}
	}
	// always return a pointer to the root
	return root;
}

Node *delete_tree(Node *root) {
	while (root != NULL) {
		root = delete_value(root, root->value);
	}
	return root;
}

void print_util(struct Node *root, int space) {
	// used to adjust spacing of nodes	
	const int SPACES=10;

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
