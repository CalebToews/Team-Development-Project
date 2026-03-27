#include "Combat.h"
#include "Functions.h"
#include <iostream>


bool attackHits(int thac0, int armorClass) {
    int roll = inclusiveRand(1, 20);

    std::cout << "Roll: " << roll << std::endl;
    std::cout << "Needed: " << (thac0 - armorClass) << std::endl;

    return roll >= (thac0 - armorClass);
}


int calculateDamage(int strength) {
    return inclusiveRand(1, strength);
}


void startCombat(Entity& player, Enemy& enemy, int playerTHAC0) {

    std::cout << "\n=== COMBAT START ===\n";
    std::cout << player.getName() << " vs " << enemy.getName() << "\n";

    while (player.isAlive() && enemy.isAlive()) {

        // ===== PLAYER TURN =====
        std::cout << "\n-- Player Turn --\n";

        if (attackHits(playerTHAC0, enemy.getArmorClass())) {
            int dmg = calculateDamage(player.getStrength());
            enemy.takeDamage(dmg);
            std::cout << "You hit for " << dmg << " damage!\n";
        }
        else {
            std::cout << "You missed!\n";
        }

        if (!enemy.isAlive()) break;

        // ===== ENEMY TURN =====
        std::cout << "\n-- Enemy Turn --\n";

        int enemyTHAC0 = 15;

        if (attackHits(enemyTHAC0, player.getArmorClass())) {
            int dmg = enemy.getAttackPower();
            player.takeDamage(dmg);
            std::cout << enemy.getName() << " hits for " << dmg << " damage!\n";
        }
        else {
            std::cout << enemy.getName() << " missed!\n";
        }

        // ===== STATUS =====
        std::cout << "\nPlayer HP: " << player.getHealth() << std::endl;
        std::cout << enemy.getName() << " HP: " << enemy.getHealth() << std::endl;

        sleepMil(800);
    }

    // ===== RESULT =====
    if (player.isAlive()) {
        std::cout << "\nYou defeated " << enemy.getName() << "!\n";
    }
    else {
        std::cout << "\nYou were defeated...\n";
    }
}