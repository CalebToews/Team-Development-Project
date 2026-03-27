#include "CombatSystem.h"
#include <iostream>

CombatSystem::CombatSystem() {
}

bool CombatSystem::attackHits(int roll, int attackBonus, int targetArmorClass) const {
    return (roll + attackBonus) >= targetArmorClass;
}

int CombatSystem::calculateDamage(int basePower, int roll) const {
    int damage = basePower + (roll / 4);
    if (damage < 1) {
        damage = 1;
    }
    return damage;
}

void CombatSystem::playerAttack(Character& player, Enemy& enemy, Dice& dice) {
    int roll = dice.role();
    int attackBonus = player.getAttackBonus();

    std::cout << "\n" << player.getName() << " attacks!" << std::endl;
    std::cout << "Roll: " << roll << " + Attack Bonus: " << attackBonus << std::endl;

    if (attackHits(roll, attackBonus, enemy.getArmorClass())) {
        int damage = calculateDamage(player.getStrength(), roll);
        enemy.takeDamage(damage);
        std::cout << "Hit! " << enemy.getName() << " takes " << damage << " damage." << std::endl;
    }
    else {
        std::cout << "Miss!" << std::endl;
    }
}

void CombatSystem::enemyAttack(Enemy& enemy, Character& player, Dice& dice) {
    int roll = dice.role();
    int attackBonus = enemy.getAttackPower();

    std::cout << "\n" << enemy.getName() << " attacks!" << std::endl;
    std::cout << "Roll: " << roll << " + Attack Bonus: " << attackBonus << std::endl;

    if (attackHits(roll, attackBonus, player.getArmorClass())) {
        int damage = calculateDamage(enemy.getStrength(), roll);
        player.takeDamage(damage);
        std::cout << "Hit! " << player.getName() << " takes " << damage << " damage." << std::endl;
    }
    else {
        std::cout << "Miss!" << std::endl;
    }
}

bool CombatSystem::runCombat(Character& player, Enemy& enemy, Dice& dice) {
    std::cout << "\n===== COMBAT START =====" << std::endl;

    while (player.isAlive() && enemy.isAlive()) {
        std::cout << "\n--- Current Status ---" << std::endl;
        std::cout << player.getName() << " HP: " << player.getHealth() << std::endl;
        std::cout << enemy.getName() << " HP: " << enemy.getHealth() << std::endl;

        playerAttack(player, enemy, dice);

        if (!enemy.isAlive()) {
            std::cout << "\n" << enemy.getName() << " has been defeated!" << std::endl;
            return true;
        }

        enemyAttack(enemy, player, dice);

        if (!player.isAlive()) {
            std::cout << "\n" << player.getName() << " has been defeated!" << std::endl;
            return false;
        }
    }

    return player.isAlive();
}