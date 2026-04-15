#include "Tree.h"
#include "Functions.h"
#include "CombatSystem.h"
#include "Dice.h"
#include "Character.h"

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

// checks how many paths there are
int directionCheck(Tree* node) {
	int sum = 0;
	if (node->left != NULL) {
		sum++;
	}
	if (node->right != NULL) {
		sum++;
	}
	return sum;
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
	if ((*node)->left == NULL || (*node)->right == NULL) {
		return NULL;
	}
	if (direction == 'l' || direction == 'y') {
		return (*node)->left;
	}
	else if (direction == 'r' || direction == 'n') {
		return (*node)->right;
	}
	return *node;
}

// function that displays messages and can start battles with enemys
void interaction(Tree* node, Character& player) {
	if (node == NULL) {
		return;
	}
	if (node->message != "") {
		if (node->message.substr(0, 2) == "H ") { // used to heal
			// using try to make sure that if a non integer value is after the H it will not break and give an error message instead
			try {
				int healthChange = std::stoi(node->message.substr(1));
				player.setHealth(player.getHealth() + healthChange);
				
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
				player.setStrength(player.getStrength() + damageChange);
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "Invalid damage change value: " << node->message.substr(2) << std::endl;
			}
			catch (const std::out_of_range& e) {
				std::cerr << "Damage change value out of range: " << node->message.substr(2) << std::endl;
			}
		}
		// if the message does not heal or increase damage then it will print the message
		else typePrint(node->message);
	}
	if (node->enemy != NULL) {
		std::cout << "\nAn enemy appears: " << node->enemy->getName() << "!" << std::endl;

		Dice d20(20);
		CombatSystem combat;

		bool playerWon = combat.runCombat(player, *node->enemy, d20);

		if (!playerWon) {
			std::cout << "\nGame Over!" << std::endl;
		}
	}
	
}