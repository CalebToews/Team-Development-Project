#pragma once
#include "Enemy.h"
#include "Character.h"
#include <iostream>

struct Tree {
	std::string message;
	Tree* left;
	Tree* right;
	Enemy* enemy;
};

void insert(Tree** node, std::string data, Enemy* enemy = NULL);

Tree* traverse(Tree** node); // use if the next node is not either left or right

Tree* traverse(Tree** node, char direction);

void interaction(Tree* node, Character& player);