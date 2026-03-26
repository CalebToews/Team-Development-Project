#pragma once
#include <iostream>
#include "Functions.h"

class Dice
{
	int sides;
public:
	Dice();
	Dice(int sides);

	int role();
	
	void draw(int num);
	void drawRand();
	void animation(int finalNum);

	int getSides();
	void setSides(int sides);

};