#include "Functions.h"

char getUserInput() {
	char input;
	std::string validInputs = "lryn";
	do {
		std::cin >> input;
		if (std::cin.fail() || validInputs.find(input) == std::string::npos) {
			std::cout << "Invalid input. Please one of the specified characters." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (std::cin.fail() || validInputs.find(input) == std::string::npos);
	return input;
}

void sleepSec(int time) {
	std::this_thread::sleep_for(std::chrono::seconds(time));
}

void sleepMil(int time) {
	std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void clear() {
	system("cls"); // clear console for windows 10/11
}

int inclusiveRand(int min, int max) {
	return std::rand() % (max - min + 1) + min;
}

// this function prints strings with a typing effect
void typePrint(std::string message) {
	for (char c : message) {
		std::cout << c;
		sleepMil(25); // Adjust typing speed here
		if (c == '\n') {
			sleepMil(500); // Pause longer at newlines
		}
	}
	std::cout << std::endl; // Move to the next line after printing the message
}