#pragma once
#include "Enemy.h"

/**
 * @file Goblin.h
 * @brief Goblin enemy class definition.
 * @author Chengcheng Sheng
 */

 /**
  * @class Goblin
  * @brief Represents a Goblin enemy.
  *
  * Goblin is the weakest enemy in the game with low HP and strength.
  * Stats: strength=6, health=15, armorClass=10.
  */
class Goblin : public Enemy {
public:
    /**
     * @brief Default constructor. Creates a Goblin with predefined stats.
     */
    Goblin();
};