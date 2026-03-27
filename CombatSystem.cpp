#include "CombatSystem.h"
#include <iostream>

//
// Constructor
// Right now it does not need special setup,
// but we keep it here in case we want to expand later.
//
CombatSystem::CombatSystem() {
}

// This function checks if an attack hits.
// Logic:
// total attack value = dice roll + attack bonus
// if total >= target armor class, the attack hits
bool CombatSystem::attackHits(int roll, int attackBonus, int targetArmorClass) const {
    return (roll + attackBonus) >= targetArmorClass;
}

// This function calculates damage.
int CombatSystem::calculateDamage(int basePower, int roll) const {
    int damage = basePower + (roll / 4);

    // Make sure damage is never below 1
    if (damage < 1) {
        damage = 1;
    }

    return damage;
}

// This handles the player's attack on the enemy.
void CombatSystem::playerAttack(Character& player, Enemy& enemy, Dice& dice) {
    // Roll the dice for the player
    int roll = dice.role();
    dice.animation(roll);

    // Get the player's attack bonus
    int attackBonus = player.getAttackBonus();

    // Calculate the total attack value
    int totalAttack = roll + attackBonus;

    // Get the enemy's armor class
    int enemyArmorClass = enemy.getArmorClass();

    std::cout << "\n" << player.getName() << " attacks!" << std::endl;

    // Show the full calculation clearly
    std::cout << "[PLAYER ROLL] Dice: " << roll
        << " + Bonus: " << attackBonus
        << " = " << totalAttack
        << " vs AC " << enemyArmorClass;

    // Check if the attack hits
    if (attackHits(roll, attackBonus, enemyArmorClass)) {
        int damage = calculateDamage(player.getStrength(), roll);
        enemy.takeDamage(damage);

        std::cout << " -> HIT! Damage: " << damage << std::endl;
    }
    else {
        std::cout << " -> MISS!" << std::endl;
    }
}

// This handles the enemy's attack on the player.
void CombatSystem::enemyAttack(Enemy& enemy, Character& player, Dice& dice) {
    // Roll the dice for the enemy
    int roll = dice.role();

    // Get the enemy's attack bonus
    int attackBonus = enemy.getAttackPower();

    // Calculate the total attack value
    int totalAttack = roll + attackBonus;

    // Get the player's armor class
    int playerArmorClass = player.getArmorClass();

    std::cout << "\n" << enemy.getName() << " attacks!" << std::endl;

    // Show the full calculation clearly
    std::cout << "[ENEMY ROLL] Dice: " << roll
        << " + Bonus: " << attackBonus
        << " = " << totalAttack
        << " vs AC " << playerArmorClass;

    // Check if the attack hits
    if (attackHits(roll, attackBonus, playerArmorClass)) {
        int damage = calculateDamage(enemy.getStrength(), roll);
        player.takeDamage(damage);

        std::cout << " -> HIT! Damage: " << damage << std::endl;
    }
    else {
        std::cout << " -> MISS!" << std::endl;
    }
}

// This runs the full combat loop until either
// the player or the enemy is defeated.
bool CombatSystem::runCombat(Character& player, Enemy& enemy, Dice& dice) {
    std::cout << "\n===== COMBAT START =====" << std::endl;

    // Continue combat while both are alive
    while (player.isAlive() && enemy.isAlive()) {
        // Display current HP before each round
        std::cout << "\n--- Current Status ---" << std::endl;
        std::cout << player.getName() << " HP: " << player.getHealth() << std::endl;
        std::cout << enemy.getName() << " HP: " << enemy.getHealth() << std::endl;

        // Player attacks first
        playerAttack(player, enemy, dice);

        // If enemy dies, player wins immediately
        if (!enemy.isAlive()) {
            std::cout << "\n" << enemy.getName() << " has been defeated!" << std::endl;
            return true;
        }

        // Enemy attacks next
        enemyAttack(enemy, player, dice);

        // If player dies, enemy wins
        if (!player.isAlive()) {
            std::cout << "\n" << player.getName() << " has been defeated!" << std::endl;
            return false;
        }
    }

    // Fallback return
    return player.isAlive();
}