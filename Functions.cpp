#include "Functions.h"

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
		std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Adjust typing speed here
		if (c == '\n') {
			std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Pause longer at newlines
		}
	}
	std::cout << std::endl; // Move to the next line after printing the message
}