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
        // clears screen
        clear();
        // displays messages and starts battles + other interactions
        interaction(map, player);

        // make sure the player is still alive after interactions
        if (!player.isAlive()) {
            std::cout << "You have died. Game Over." << std::endl;
            break;
        }

		// checks how many directions there are (2 = choice, 1 = no choice, 0 = end of map)
        directionCount = directionCheck(map);

        if (directionCount == 2) { // 2 = choice
            userInput = getUserInput();
            map = traverse(&map, userInput);
        }
		else if (directionCount == 1) { // 1 = no choice
			sleepSec(2);
			map = traverse(&map);
        }
		else { // 0 = end of map
            typePrint("You have reached the end of the map, Congrats");
            break;
        }

        
    }


    return 0;
}