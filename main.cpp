#include "main.h"
#include "Character.h"
#include "Enemy.h"
#include "CombatSystem.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    // Seed random number generator
    std::srand(std::time(0));

    // Create dice (D20)
    Dice d20(20);

    // ===== GAME START =====
    std::cout << "===== GAME START =====\n" << std::endl;

    // Create player
    Character player("Arin", "Warrior", 10, 30, 12);

    // Display player info
    std::cout << "===== PLAYER =====" << std::endl;
    player.displayCharacter();

    // Create enemy
    Enemy goblin("Gob", "Goblin", 8, 20, 10);

    // Display enemy info
    std::cout << "\n===== ENEMY =====" << std::endl;
    goblin.displayEnemy();

    // ===== COMBAT =====
    std::cout << "\n===== COMBAT =====" << std::endl;

    CombatSystem combat;
    bool playerWon = combat.runCombat(player, goblin, d20);

    // ===== RESULT =====
    std::cout << "\n===== RESULT =====" << std::endl;

    if (playerWon) {
        std::cout << player.getName() << " wins the battle!" << std::endl;
    }
    else {
        std::cout << goblin.getName() << " wins the battle!" << std::endl;
    }

    std::cout << "\n===== GAME END =====" << std::endl;

    return 0;
}