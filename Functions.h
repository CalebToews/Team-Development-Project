#pragma once

#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>

char getUserInput();

void sleepSec(int time);
void sleepMil(int time);

void clear();

int inclusiveRand(int min, int max);

void typePrint(std::string);