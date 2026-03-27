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
    player.displayCharacter();

    return 0;
}