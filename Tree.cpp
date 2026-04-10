#include "Tree.h"
#include "Functions.h"


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
		if (node->message.substr(0, 2) == "H ") { // used to heal
			// using try to make sure that if a non integer value is after the H it will not break and give an error message instead
			try {
				int healthChange = std::stoi(node->message.substr(1));
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "Invalid health change value: " << node->message.substr(2) << std::endl;
			}
			catch (const std::out_of_range& e) {
				std::cerr << "Health change value out of range: " << node->message.substr(2) << std::endl;
			}
		}
		else if (node->message.substr(0, 2) == "D ") { // used to increase damage
			// using try to make sure that if a non integer value is after the D it will not break and give an error message instead
			try {
				int damageChange = std::stoi(node->message.substr(1));
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "Invalid health change value: " << node->message.substr(2) << std::endl;
			}
			catch (const std::out_of_range& e) {
				std::cerr << "Health change value out of range: " << node->message.substr(2) << std::endl;
			}
		}
		// if the message does not heal or increase damage then it will print the message
		else typePrint(node->message);
	}
	if (node->enemy != NULL) {
		// interacting with enemys (battle system)
	}
	
}