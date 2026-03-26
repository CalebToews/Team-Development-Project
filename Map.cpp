#include "Map.h"
#include "Enemy.h"
#include <iostream>

// this is where the map will be build (the tree structure will be setup)
void mapBuild(Tree** root) {
	std::cout << "Map Build / Tree Setup" << std::endl;

	Tree* temp = *root;

	insert(&temp, "You woke up in a forest near a town with a headache. You can't remember where you are or how you got here. \n \nYou start walkinig towards the town and on they way see an elderly man being attacked by a thief.\nInput yes or no (y or n):\n");
	
	insert(&temp->left, "You decid to attack the thief", NULL /*replace NULL with thief enemy here*/);

	insert(&temp->right, "You walk into a nearby Town. You are shunned by villagers. But later approached by a strange man that offers you a place in his Rebel group");

}