#include "Map.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Orc.h"
#include "Dragon.h"
#include <iostream>

// this is where the map will be build (the tree structure will be setup)
void mapBuild(Tree** root) {

	Tree* temp = *root;

	// ROOT NODE
	insert(&temp, "You woke up in a forest near a town with a headache. You can't remember where you are or how you got here.\n\nYou start walking towards the town and on the way see an elderly man being attacked by a goblin. Do you defend the elderly man?\nInput yes or no (y or n): ");

	// ===== LEFT PATH ===== (defend the old man)
	insert(&temp->left, "You decide to attack the goblin!", new Goblin());

	insert(&temp->left->left, "For helping the elderly man, he offers you a place to sleep in his village.\nDo you accept his offer? (y or n): ");

	// Accept offer
	insert(&temp->left->left->left, "You accept the offer and sleep in the man's house.");
	insert(&temp->left->left->left->left, "H 10"); // +10 health

	// Decline offer
	insert(&temp->left->left->right, "You think the elderly man talks too much so you decide to decline his offer and sleep outside on a bench.\nThe man gives you blankets anyway.");

	// Both paths converge to Dragon dungeon
	insert(&temp->left->left->left->left->left,
		"Next morning the elderly man gives you a compass.\nLater you overhear villagers speaking of a Dungeon to the south guarded by a DRAGON. You decide to check it out.",
		new Dragon());
	temp->left->left->right->left = temp->left->left->left->left->left;

	// Dragon ending
	insert(&temp->left->left->left->left->left->left,
		"You defeated the Dragon and claimed the ancient artifacts! The village celebrates you as a hero.\n\n===== YOU WIN! =====");

	// ===== RIGHT PATH ===== (ignore goblin)
	insert(&temp->right, "You decide to ignore the goblin.\nYou walk into a nearby Town. You are shunned by villagers, but later approached by a strange man who offers you a place in his Rebel group.\nDo you accept his offer? (y or n):");

	// Accept rebel offer
	insert(&temp->right->left, "You accept his offer and join the Rebel group.\nThe man hands you a stone dagger and brings you to his camp to rest.");
	insert(&temp->right->left->left, "D 5"); // +5 damage from dagger
	insert(&temp->right->left->left->left, "H 5"); // +5 health from rest
	insert(&temp->right->left->left->left->left,
		"The next day the Rebel Leader announces a dungeon raid. As the newest member, you have no choice but to go.\nYou enter the dungeon and encounter a fearsome Orc!",
		new Orc());
	insert(&temp->right->left->left->left->left->left,
		"You defeated the Orc and claimed the dungeon treasure for the Rebel group!\nYour reputation grows and you are welcomed as a true member.\n\n===== YOU WIN! =====");

	// Decline rebel offer
	insert(&temp->right->right, "The rebel pushes you.\nNight is approaching so you rest in an abandoned building.");
	insert(&temp->right->right->left, "H -2"); // -2 health from poor sleep
	insert(&temp->right->right->left->left,
		"In the morning the rebel leader finds you sleeping in his childhood home and sends his enraged Orc to attack you!",
		new Orc());
	insert(&temp->right->right->left->left->left,
		"You defeated the Orc! The rebel leader, impressed by your strength, offers you a place in the group.\nYou accept and together raid the dungeon for glory.\n\n===== YOU WIN! =====");

	*root = temp;
}