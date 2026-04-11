#include "Map.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Orc.h"
#include "Dragon.h"
#include <iostream>

// this is where the map will be build (the tree structure will be setup)
void mapBuild(Tree** root) {
	std::cout << "Map Build / Tree Setup" << std::endl;

	Tree* temp = *root;

	insert(&temp, "You woke up in a forest near a town with a headache. You can't remember where you are or how you got here. \n \nYou start walkinig towards the town and on they way see an elderly man being attacked by a thief. Do you defend the elderly man\nInput yes or no (y or n): ");
	
	// ----- FIRST CHOICE LEFT PATH ----- (ATTACK THIEF)
	insert(&temp->left, "You decid to attack the thief", new Goblin());

	insert(&temp->left->left, "For helping the elderly man, he offerse you a place to sleep in his village. \nDo you accept his offer? (y or n): ");

		// ----- SECOND CHOICE LEFT PATH ----- (accept and decline lead to same place)

	insert(&temp->left->left->left, "You accept the offer and sleep in the man's house. \n +10 Heatlh");
	insert(&temp->left->left->left->left, "H 10"); // used to heal the player by 10 health points, the interaction function will check for this and heal the player accordingly)
	insert(&temp->left->left->right, "You think the elderly man talks too much so you decide to decline his offer and sleep outside his house on a bench.\nThe man decides to give you blankets anyway.");

	insert(&temp->left->left->left->left->left, "Next morning the elderly man gives you a compass so you don't lose your way again. \nLater that morning you overhear 2 villagers speaking of a Dungeon to the south that contains ancient artifacts guarded by a goblin. You decide to go check it out.");
	temp->left->left->right->left = temp->left->left->left->left->left; // both paths lead to the same place

	// ----- FIRST CHOICE RIGHT PATH ----- (ignore thief)

	insert(&temp->right, "You decide to ignore the thief.\nYou walk into a nearby Town. You are shunned by villagers. But later approached by a strange man that offers you a place in his Rebel group.\nDo you accept his offer. (y or n):");

	insert(&temp->right->left, "You accept his offer and join the Rebel group.\nThe man hands you a stone dagger and brings your to his camp to rest for the night.\n(+5 damage from dagger) (+5 health from rest).\n\nThe next day the Rebal Leader announces that he needs volentears to raid a dungeon.\nYou however do not get a choice because you are new.");

	insert(&temp->right->right, "The rebal pushes you and you take 1 hp from emotion damage.\n(-1 Health)\n\nNight is approching so you decide to rest in an abandoned building outside the the village.\n(-2 health from getting a pour sleep.\n In the morning the rebal leader finds you sleeping in his childhood home and attacks you.", new Orc());

	insert(&temp->right->right->left, "After defeating the rebel leader you take over his group. The group tells you about a dungeons that has been found and that they think they should check it out.");
		
	*root = temp;

}