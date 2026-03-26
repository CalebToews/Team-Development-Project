#include "main.h"

// testing if can commit

int main() {
	std::srand(std::time(0)); // set seed for random numbers (needed for dice class)

	Dice d20(20);
	int num = d20.role();
	d20.animation(num);
	std::cout << "You got a: " << num << std::endl;

}