#pragma once
#include "Enemy.h"

/**
 * @file Dragon.h
 * @brief Dragon enemy class definition.
 * @author Chengcheng Sheng
 */

 /**
  * @class Dragon
  * @brief Represents a Dragon enemy — the strongest monster in the game.
  *
  * Dragon is the boss enemy with high HP and strength.
  * Stats: strength=20, health=50, armorClass=16.
  */
class Dragon : public Enemy {
public:
    /**
     * @brief Default constructor. Creates a Dragon with predefined stats.
     */
    Dragon();
};