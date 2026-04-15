#pragma once

struct Traits {
    int strength;
    int agility;
    int speed;
    int intelligence;

    Traits() : strength(0), agility(0), speed(0), intelligence(0) {}

    Traits(int str, int agi, int spd, int intel)
        : strength(str), agility(agi), speed(spd), intelligence(intel) {
    }
};
