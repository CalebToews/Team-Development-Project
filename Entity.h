#pragma once
#include <string>

/**
 * @file Entity.h
 * @brief Base entity class definition.
 * @author Caleb Toews
 */

 /**
  * @class Entity
  * @brief Base class for all combat participants in the game.
  *
  * Entity provides shared attributes and methods for both
  * player characters and enemy monsters including HP management,
  * armor class, and damage handling.
  */
class Entity {
protected:
    std::string name;  ///< The entity's name
    int strength;      ///< Physical strength value
    int health;        ///< Current health points
    int armorClass;    ///< Armor class value used in hit calculations
    int thac0;         ///< To Hit Armor Class 0 value

public:
    /**
     * @brief Default constructor. Initializes all values to 0.
     */
    Entity();

    /**
     * @brief Parameterized constructor.
     * @param name The entity's name.
     * @param strength The strength value.
     * @param health The health points.
     * @param armorClass The armor class value.
     */
    Entity(std::string name, int strength, int health, int armorClass);

    /** @brief Gets the entity's name. @return Name as string. */
    std::string getName() const;

    /** @brief Gets the entity's strength. @return Strength value. */
    int getStrength() const;

    /** @brief Gets the entity's current health. @return Health points. */
    int getHealth() const;

    /** @brief Gets the entity's armor class. @return Armor class value. */
    int getArmorClass() const;

    /** @brief Sets the entity's name. @param name New name. */
    void setName(std::string name);

    /** @brief Sets the entity's strength. @param strength New strength. */
    void setStrength(int strength);

    /** @brief Sets the entity's health. @param health New health value. */
    void setHealth(int health);

    /** @brief Sets the entity's armor class. @param armorClass New armor class. */
    void setArmorClass(int armorClass);

    /**
     * @brief Reduces health by the given damage amount.
     * @param damage Amount of damage to apply. HP will not go below 0.
     */
    void takeDamage(int damage);

    /**
     * @brief Checks if the entity is alive.
     * @return True if health > 0.
     */
    bool isAlive() const;
};