#include "Dice.h"


Dice::Dice() {
	sides = 6;
}

Dice::Dice(int sides) {
	this->sides = sides;
}

int Dice::role() {
	return inclusiveRand(1, sides);
}

void Dice::draw(int num) {
	std::cout << "+-------+" << std::endl;
	std::cout << "|       |" << std::endl;
	if (num < 10) {
		std::cout << "|   " << num << "   |" << std::endl;
	}
	else {
		std::cout << "|   " << num << "  |" << std::endl;
	}
	std::cout << "|       |" << std::endl;
	std::cout << "+-------+" << std::endl;
}

void Dice::drawRand() {
	draw(role());
}

void Dice::animation(int finalNum) {
	for (int i = 0; i < 10; i++) {
		sleepMil(100 + i * 30);
		clear();
		drawRand();
	}
	sleepMil(500);
	clear();
	draw(finalNum);
}

int Dice::getSides() {
	return sides;
}

void Dice::setSides(int sides) {
	this->sides = sides;
}

/* possible 3d dice drawing
   +--------+
  /        /|
 /        / |
+--------+  |
|        |  +
|        | /
|        |/
+--------+
    +------------+
   /            /|
  /    num     / |
 /            /  |
+------------+   |
|            |   |
|            |   +
|            |  /
|            | /
|            |/
+------------+

*/