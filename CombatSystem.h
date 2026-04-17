#pragma once
#include "Character.h"
#include "Enemy.h"
#include "Dice.h"

/**
 * @file CombatSystem.h
 * @brief Combat system class definition.
 * @author Marcus Tirbany
 */

 /**
  * @class CombatSystem
  * @brief Handles all battle mechanics between the player and enemies.
  *
  * CombatSystem implements hit calculation using dice rolls and armor class,
  * damage calculation based on base power and roll, and a full turn-based
  * combat loop via runCombat().
  */
class CombatSystem {
public:
    /**
     * @brief Default constructor.
     */
    CombatSystem();

    /**
     * @brief Determines if an attack hits based on roll, bonus, and target AC.
     * @param roll The dice roll value.
     * @param attackBonus The attacker's attack bonus.
     * @param targetArmorClass The target's armor class.
     * @return True if roll + attackBonus >= targetArmorClass.
     */
    bool attackHits(int roll, int attackBonus, int targetArmorClass) const;

    /**
     * @brief Calculates damage based on base power and dice roll.
     * @param basePower The attacker's base power (strength).
     * @param roll The dice roll value.
     * @return Damage value, minimum 1.
     */
    int calculateDamage(int basePower, int roll) const;

    /**
     * @brief Executes the player's attack on an enemy.
     * @param player The player character.
     * @param enemy The target enemy.
     * @param dice The dice object for rolling.
     */
    void playerAttack(Character& player, Enemy& enemy, Dice& dice);

    /**
     * @brief Executes the enemy's attack on the player.
     * @param enemy The attacking enemy.
     * @param player The player character.
     * @param dice The dice object for rolling.
     */
    void enemyAttack(Enemy& enemy, Character& player, Dice& dice);

    /**
     * @brief Runs the full combat loop until one side is defeated.
     * @param player The player character.
     * @param enemy The enemy.
     * @param dice The dice object.
     * @return True if player wins, false if player is defeated.
     */
    bool runCombat(Character& player, Enemy& enemy, Dice& dice);
};