#pragma once
#include "Enemy.h"
#include "Character.h"
#include <iostream>

/**
 * @file Tree.h
 * @brief Binary tree structure for story navigation.
 * @author Nathaniel Toews
 */

 /**
  * @struct Tree
  * @brief Represents a node in the story binary tree.
  *
  * Each node contains a story message, optional enemy encounter,
  * and pointers to left and right child nodes representing choices.
  */
struct Tree {
    std::string message; ///< The narrative text for this story node
    Tree* left;          ///< Left child node (yes/left choice)
    Tree* right;         ///< Right child node (no/right choice)
    Enemy* enemy;        ///< Optional enemy encounter at this node
};

/**
 * @brief Inserts a new node into the tree.
 * @param node Pointer to the node pointer to insert at.
 * @param data The story message for the new node.
 * @param enemy Optional enemy pointer for combat encounters.
 */
void insert(Tree** node, std::string data, Enemy* enemy = NULL);

/**
 * @brief Checks how many valid directions exist from current node.
 * @param node The current tree node.
 * @return Number of available directions (0, 1, or 2).
 */
int directionCheck(Tree* node);

/**
 * @brief Traverses to the next node when there is no player choice.
 * @param node Pointer to the current node pointer.
 * @return Pointer to the next node.
 */
Tree* traverse(Tree** node);

/**
 * @brief Traverses to a child node based on player direction input.
 * @param node Pointer to the current node pointer.
 * @param direction Direction character ('l'/'y' for left, 'r'/'n' for right).
 * @return Pointer to the chosen child node.
 */
Tree* traverse(Tree** node, char direction);

/**
 * @brief Processes a story node — displays text, applies effects, triggers combat.
 * @param node The current story node.
 * @param player Reference to the player character.
 */
void interaction(Tree* node, Character& player);