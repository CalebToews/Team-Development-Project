#pragma once

#include "Entity.h"
#include "Enemy.h"


bool attackHits(int thac0, int armorClass);

int calculateDamage(int strength);


void startCombat(Entity & player, Enemy & enemy, int playerTHAC0);
