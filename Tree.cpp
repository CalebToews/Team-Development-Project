#include "Tree.h"


// function used to add a node to the tree map
void insert(Tree** node, std::string message, Enemy* enemy) {
	if (*node == NULL) {
		*node = new Tree();
		(*node)->message = message;
		(*node)->enemy = enemy;
		(*node)->left = NULL;
		(*node)->right = NULL;
	}
	return;
}

// function to move down a path if there is no choice
Tree* traverse(Tree** node) {
	if ((*node)->left == NULL && (*node)->right == NULL) {
		return *node;
	}
	else if ((*node)->left == NULL) {
		return (*node)->right;
	}
	else {
		return (*node)->left;
	}
}

// function to choose which direction will be taken
Tree* traverse(Tree** node, char direction) {
	if (direction == 'l') {
		return (*node)->left;
	}
	else if (direction == 'r') {
		return (*node)->right;
	}
	return *node;
}

// function that displays messages and can start battles with enemys
void interaction(Tree* node) {
	if (node == NULL) {
		return;
	}
	if (node->message != "") {
		std::cout << node->message << std::endl;
	}
	if (node->enemy != NULL) {
		// interacting with enemys (battle system)
	}
}