#pragma once
#include <iostream>
#include "Functions.h"

/**
 * @file Dice.h
 * @brief Dice class definition for random number generation.
 * @author Caleb Toews
 */

 /**
  * @class Dice
  * @brief Simulates a dice roll for combat and game mechanics.
  *
  * The Dice class provides configurable dice rolling functionality
  * used throughout the game, primarily as a D20 for combat calculations.
  */
class Dice {
    int sides; ///< Number of sides on the dice
public:
    /**
     * @brief Default constructor. Creates a 6-sided dice.
     */
    Dice();

    /**
     * @brief Parameterized constructor.
     * @param sides Number of sides on the dice.
     */
    Dice(int sides);

    /**
     * @brief Rolls the dice and returns a random value.
     * @return Random integer between 1 and sides inclusive.
     */
    int role();

    /**
     * @brief Draws the dice face for a given number.
     * @param num The number to display.
     */
    void draw(int num);

    /**
     * @brief Draws a random dice face.
     */
    void drawRand();

    /**
     * @brief Animates the dice roll ending on the final number.
     * @param finalNum The final rolled value to display.
     */
    void animation(int finalNum);

    /** @brief Gets the number of sides. @return Number of sides. */
    int getSides();

    /** @brief Sets the number of sides. @param sides New number of sides. */
    void setSides(int sides);
};