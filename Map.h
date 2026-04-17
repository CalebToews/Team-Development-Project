#pragma once
#include "Tree.h"

/**
 * @file Map.h
 * @brief Map building function for story tree initialization.
 * @author Nathaniel Toews
 */

 /**
  * @brief Builds the complete story tree with all nodes and enemy encounters.
  * @param root Pointer to the root node pointer of the story tree.
  */
void mapBuild(Tree** root);