#pragma once

#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>

/**
 * @file Functions.h
 * @brief Utility functions used throughout the game.
 * @author Caleb Toews
 */

 /**
  * @brief Pauses execution for a given number of seconds.
  * @param time Number of seconds to sleep.
  */
void sleepSec(int time);

/**
 * @brief Pauses execution for a given number of milliseconds.
 * @param time Number of milliseconds to sleep.
 */
void sleepMil(int time);

/**
 * @brief Clears the console screen.
 */
void clear();

/**
 * @brief Generates a random integer between min and max inclusive.
 * @param min Minimum value.
 * @param max Maximum value.
 * @return Random integer in range [min, max].
 */
int inclusiveRand(int min, int max);

/**
 * @brief Gets a single character input from the player.
 * @return The character entered by the player.
 */
char getUserInput();

/**
 * @brief Prints a string to the console with a typing animation effect.
 * @param message The string to print.
 */
void typePrint(std::string message);