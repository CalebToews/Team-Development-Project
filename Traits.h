#pragma once

/**
 * @file Traits.h
 * @brief Traits struct definition for player character attributes.
 * @author Ngoc Thanh Thi Nguyen
 */

 /**
  * @struct Traits
  * @brief Stores the core attribute values for a player character.
  *
  * Traits are initialized at character creation based on class type
  * and are used by the Character module to calculate attack bonuses
  * and dodge values.
  */
struct Traits {
    int strength;      ///< Physical power — affects melee damage
    int agility;       ///< Quickness — affects dodge and Rogue attacks
    int speed;         ///< Movement and turn priority
    int intelligence;  ///< Magic power — affects Mage attacks

    /**
     * @brief Default constructor. Sets all traits to 0.
     */
    Traits() : strength(0), agility(0), speed(0), intelligence(0) {}

    /**
     * @brief Parameterized constructor.
     * @param str  Strength value.
     * @param agi  Agility value.
     * @param spd  Speed value.
     * @param intel Intelligence value.
     */
    Traits(int str, int agi, int spd, int intel)
        : strength(str), agility(agi), speed(spd), intelligence(intel) {
    }
};
