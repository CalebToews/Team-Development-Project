#include "main.h"
#include "Character.h"
#include "Combat.h"

int main() {
    std::srand(std::time(0));

    // ===== TEST DICE =====
    Dice d20(20);
    int num = d20.role();
    d20.animation(num);
    std::cout << "You got a: " << num << std::endl;

    std::cout << "---------------------" << std::endl;

    /*
    // ===== TEST CHARACTER =====
    Character player("Arin", "Warrior", 10, 30, 12);
    player.displayCharacter();

    */
    // ===== TEST COMBAT ========
    Entity player("Arin", 10, 30, 12);
    Enemy goblin("Gob", "Goblin", 8, 20, 10);
            
    int playerTHAC0 = 15;

    startCombat(player, goblin, playerTHAC0);

    return 0;
}