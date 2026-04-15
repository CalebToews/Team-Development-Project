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


bool startCombat(Entity& player, Enemy& enemy, int playerTHAC0) {

    std::cout << "\n=== COMBAT START ===\n";
    std::cout << player.getName() << " vs " << enemy.getName() << "\n";

    while (player.isAlive() && enemy.isAlive()) {


        std::cout << "\n-- Player Turn --\n";

        int choice;
        std::cout << "1. Attack\n2. Defend\nChoice: ";
        std::cin >> choice;

        if (choice == 1) {
            int roll = inclusiveRand(1, 20);

            std::cout << "Roll: " << roll << std::endl;
            std::cout << "Needed: " << (playerTHAC0 - enemy.getArmorClass()) << std::endl;

            if (roll >= (playerTHAC0 - enemy.getArmorClass())) {
                int dmg = calculateDamage(player.getStrength());

 
                if (roll == 20) {
                    std::cout << "CRITICAL HIT!\n";
                    dmg *= 2;
                }

                enemy.takeDamage(dmg);
                std::cout << "You hit for " << dmg << " damage!\n";
            }
            else {
                std::cout << "You missed!\n";
            }
        }
        else if (choice == 2) {
            std::cout << "You brace for impact! (Reduced damage this turn)\n";
        }

        if (!enemy.isAlive()) break;


        std::cout << "\n-- Enemy Turn --\n";


        int enemyTHAC0 = enemy.getTHAC0();

        int roll = inclusiveRand(1, 20);
        std::cout << enemy.getName() << " rolls: " << roll << std::endl;

        if (roll >= (enemyTHAC0 - player.getArmorClass())) {
            int dmg = enemy.getAttackPower();

            if (roll == 20) {
                std::cout << enemy.getName() << " lands a CRITICAL HIT!\n";
                dmg *= 2;
            }

            if (choice == 2) {
                dmg /= 2;
                std::cout << "Your defense reduces the damage!\n";
            }

            player.takeDamage(dmg);
            std::cout << enemy.getName() << " hits for " << dmg << " damage!\n";
        } 
        else {
            std::cout << enemy.getName() << " missed!\n";
        }


        std::cout << "\nPlayer HP: " << player.getHealth() << std::endl;
        std::cout << enemy.getName() << " HP: " << enemy.getHealth() << std::endl;

        sleepMil(800);
    }


    if (player.isAlive()) {
        std::cout << "\nYou defeated " << enemy.getName() << "!\n";
		return true;
    }
    else {
        std::cout << "\nYou were defeated...\n";
        return false;
    }
}