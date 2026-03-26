#pragma once

#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

void sleepSec(int time);
void sleepMil(int time);

void clear();

int inclusiveRand(int min, int max);