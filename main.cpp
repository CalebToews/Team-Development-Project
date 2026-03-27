#include "main.h"
#include "Character.h"

int main() {
    std::srand(std::time(0));

    // ===== TEST DICE =====
    Dice d20(20);
    int num = d20.role();
    d20.animation(num);

    std::cout << "You got a: " << num << std::endl;

    std::cout << "---------------------" << std::endl;

    // ===== TEST CHARACTER =====
    Character player("Arin", "Warrior", 10, 30, 12);

    std::cout << "Player: " << player.getName() << std::endl;
    std::cout << "Class: " << player.getClassType() << std::endl;
    std::cout << "HP: " << player.getHealth() << std::endl;
    std::cout << "Attack Bonus: " << player.getAttackBonus() << std::endl;

    return 0;
}