#pragma once
#include "Entity.h"
#include <string>

/**
 * @file Enemy.h
 * @brief Enemy class definition.
 * @author Chengcheng Sheng
 */

 /**
  * @class Enemy
  * @brief Represents an enemy entity in the game.
  *
  * Enemy extends Entity with enemy-specific attributes including
  * enemy type, attack power, and THAC0 value for combat calculations.
  */
class Enemy : public Entity {
private:
    std::string enemyType; ///< The type of enemy (Goblin, Orc, Dragon)

public:
    /**
     * @brief Default constructor. Creates a Goblin with default stats.
     */
    Enemy();

    /**
     * @brief Parameterized constructor.
     * @param name The enemy's name.
     * @param enemyType The type of enemy.
     * @param strength The enemy's strength.
     * @param health The enemy's health points.
     * @param armorClass The enemy's armor class.
     */
    Enemy(const std::string& name, const std::string& enemyType, int strength, int health, int armorClass);

    /** @brief Gets the enemy type. @return Enemy type as string. */
    std::string getEnemyType() const;

    /** @brief Sets the enemy type. @param enemyType New enemy type. */
    void setEnemyType(const std::string& enemyType);

    /**
     * @brief Calculates attack power based on strength.
     * @return Attack power value.
     */
    int getAttackPower() const;

    /**
     * @brief Gets the enemy's THAC0 value.
     * @return THAC0 value used in hit calculations.
     */
    int getTHAC0() const;

    /**
     * @brief Displays enemy stats to the console.
     */
    void displayEnemy() const;
};