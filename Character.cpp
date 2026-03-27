#include "Character.h"
#include <iostream>

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

bool Character::isWarrior() const {
    return classType == "Warrior";
}

bool Character::isMage() const {
    return classType == "Mage";
}

bool Character::isRogue() const {
    return classType == "Rogue";
}

bool Character::isValidClassType() const {
    return classType == "Warrior" || classType == "Mage" || classType == "Rogue";
}

void Character::displayCharacter() const {
    std::cout << "Player: " << getName() << std::endl;
    std::cout << "Class: " << classType << std::endl;
    std::cout << "HP: " << getHealth() << std::endl;
    std::cout << "Strength: " << getStrength() << std::endl;
    std::cout << "Armor Class: " << getArmorClass() << std::endl;
    std::cout << "Attack Bonus: " << getAttackBonus() << std::endl;
    std::cout << "Dodge Value: " << getDodgeValue() << std::endl;
}