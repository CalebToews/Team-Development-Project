#include "main.h"

int main() {
    // Seed random number generator
    std::srand(std::time(0));

    // Create dice (D20)
    Dice d20(20);

    // ===== GAME START =====
    std::cout << "===== GAME START =====\n" << std::endl;

    // ===== TEST CHARACTER =====
    Character player = Character::createFromConsole();

    // Display player info
    std::cout << "===== PLAYER =====" << std::endl;
    player.displayCharacter();

	// Get user input to start the game
	std::cout << "\nPress Enter to start the game...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer
    std::cin.get();

    // ----------------- basic game loop test

    char userInput;
	int directionCount = 0;
    Tree* map = NULL;
	mapBuild(&map);

    while (true) {
        clear();
        interaction(map, player);
        directionCount = directionCheck(map);
        if (!player.isAlive()) {
            std::cout << "You have died. Game Over." << std::endl;
            break;
        }
        
        if (directionCount == 2) {
            userInput = getUserInput();
            map = traverse(&map, userInput);
        }
        else if (directionCount == 1) {
			map = traverse(&map);
        }
        else {
            typePrint("You have reached the end of the map, Congrats");
            break;
        }

        
    }


    return 0;
}