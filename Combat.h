#pragma once

#include "Entity.h"
#include "Enemy.h"

/**
 * @file Combat.h
 * @brief Standalone combat functions using THAC0 mechanics.
 * @author Marcus Tirbany
 */

 /**
  * @brief Determines if an attack hits using THAC0 and armor class.
  * @param thac0 The attacker's THAC0 value.
  * @param armorClass The target's armor class.
  * @return True if a random roll meets or exceeds the hit threshold.
  */
bool attackHits(int thac0, int armorClass);

/**
 * @brief Calculates damage based on attacker's strength.
 * @param strength The attacker's strength value.
 * @return Random damage value between 1 and strength.
 */
int calculateDamage(int strength);

/**
 * @brief Runs a full combat encounter between a player and an enemy.
 * @param player Reference to the player Entity.
 * @param enemy Reference to the Enemy.
 * @param playerTHAC0 The player's THAC0 value.
 * @return True if player wins, false if player is defeated.
 */
bool startCombat(Entity& player, Enemy& enemy, int playerTHAC0);
