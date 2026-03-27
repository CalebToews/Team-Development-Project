#include "Character.h"

Character::Character() : Entity() {
    classType = "Warrior";
}

Character::Character(std::string name, std::string classType, int strength, int health, int armorClass)
    : Entity(name, strength, health, armorClass) {
    this->classType = classType;
}

std::string Character::getClassType() const {
    return classType;
}

void Character::setClassType(std::string classType) {
    this->classType = classType;
}

int Character::getAttackBonus() const {
    if (classType == "Warrior") {
        return strength / 2;
    }
    else if (classType == "Mage") {
        return strength / 3;
    }
    else if (classType == "Rogue") {
        return strength / 2;
    }
    return 0;
}

int Character::getDodgeValue() const {
    if (classType == "Rogue") {
        return armorClass + 2;
    }
    return armorClass;
}