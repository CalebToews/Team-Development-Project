#pragma once
#include "Enemy.h"

/**
 * @file Orc.h
 * @brief Orc enemy class definition.
 * @author Chengcheng Sheng
 */

 /**
  * @class Orc
  * @brief Represents an Orc enemy.
  *
  * Orc is a mid-tier enemy with moderate HP and strength.
  * Stats: strength=10, health=25, armorClass=12.
  */
class Orc : public Enemy {
public:
    /**
     * @brief Default constructor. Creates an Orc with predefined stats.
     */
    Orc();
};