#pragma once
#include "Entity.h"
#include "Traits.h"
#include <string>

/**
 * @file Character.h
 * @brief Player character class definition.
 * @author Ngoc Thanh Thi Nguyen
 */

 /**
  * @class Character
  * @brief Represents the player-controlled character in the game.
  *
  * The Character class manages player creation, class selection,
  * trait initialization, and stat tracking throughout gameplay.
  * It inherits from Entity and provides combat-related statistics
  * to the Combat module.
  */
class Character : public Entity {
private:
    std::string classType; ///< The class type of the character (Warrior, Mage, Rogue)
    Traits traits;         ///< The character's trait values based on class type

public:
    /**
     * @brief Default constructor. Creates a Warrior with default stats.
     */
    Character();

    /**
     * @brief Parameterized constructor.
     * @param name The character's name.
     * @param classType The class type (Warrior, Mage, or Rogue).
     * @param strength The base strength value.
     * @param health The base health points.
     * @param armorClass The base armor class value.
     */
    Character(std::string name, std::string classType, int strength, int health, int armorClass);

    /**
     * @brief Gets the character's class type.
     * @return The class type as a string.
     */
    std::string getClassType() const;

    /**
     * @brief Sets the character's class type.
     * @param classType The new class type.
     */
    void setClassType(std::string classType);

    /**
     * @brief Gets the character's traits.
     * @return The Traits struct containing all attribute values.
     */
    Traits getTraits() const;

    /**
     * @brief Calculates the attack bonus based on class type and traits.
     * @return The attack bonus value.
     */
    int getAttackBonus() const;

    /**
     * @brief Calculates the dodge value based on class type and armor class.
     * @return The dodge value.
     */
    int getDodgeValue() const;

    /**
     * @brief Checks if the character is a Warrior.
     * @return True if classType is Warrior.
     */
    bool isWarrior() const;

    /**
     * @brief Checks if the character is a Mage.
     * @return True if classType is Mage.
     */
    bool isMage() const;

    /**
     * @brief Checks if the character is a Rogue.
     * @return True if classType is Rogue.
     */
    bool isRogue() const;

    /**
     * @brief Validates the class type.
     * @return True if classType is Warrior, Mage, or Rogue.
     */
    bool isValidClassType() const;

    /**
     * @brief Displays all character stats to the console.
     */
    void displayCharacter() const;

    /**
     * @brief Creates a Character from console input.
     * @return A new Character object based on user input.
     */
    static Character createFromConsole();
};