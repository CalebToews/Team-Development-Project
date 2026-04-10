#include "main.h"

int main() {
    // Seed random number generator
    std::srand(std::time(0));

    // Create dice (D20)
    Dice d20(20);

    // ===== GAME START =====
    std::cout << "===== GAME START =====\n" << std::endl;

    // ===== TEST CHARACTER =====
    Character player("Arin", "Warrior", 10, 30, 12);

    // Display player info
    std::cout << "===== PLAYER =====" << std::endl;
    player.displayCharacter();



    // ----------------- basic game loop test
    char userInput = 'r';
    Tree* map = NULL;
	mapBuild(&map);

    while (true) {

		interaction(map);
		map = traverse(&map, userInput);

    }


    return 0;
}