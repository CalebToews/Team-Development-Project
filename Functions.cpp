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