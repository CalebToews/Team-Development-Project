#include "Character.h"
#include <iostream>

Character::Character() : Entity("Player", 10, 30, 12) {
    classType = "Warrior";
    traits = Traits(8, 4, 4, 2);
}

Character::Character(std::string name, std::string classType, int strength, int health, int armorClass)
    : Entity(name, strength, health, armorClass) {
    this->classType = classType;

    if (classType == "Warrior")
        traits = Traits(8, 4, 4, 2);
    else if (classType == "Mage")
        traits = Traits(3, 4, 4, 9);
    else if (classType == "Rogue")
        traits = Traits(5, 9, 7, 3);
    else
        traits = Traits();
}

std::string Character::getClassType() const {
    return classType;
}

void Character::setClassType(std::string classType) {
    this->classType = classType;
}

Traits Character::getTraits() const {
    return traits;
}

int Character::getAttackBonus() const {
    if (classType == "Warrior")
        return traits.strength / 2;
    else if (classType == "Mage")
        return traits.intelligence / 2;
    else if (classType == "Rogue")
        return traits.agility / 2;
    return 0;
}

int Character::getDodgeValue() const {
    if (classType == "Rogue")
        return armorClass + traits.agility / 3;
    return armorClass;
}

bool Character::isWarrior() const { return classType == "Warrior"; }
bool Character::isMage()    const { return classType == "Mage"; }
bool Character::isRogue()   const { return classType == "Rogue"; }

bool Character::isValidClassType() const {
    return classType == "Warrior" || classType == "Mage" || classType == "Rogue";
}

void Character::displayCharacter() const {
    std::cout << "Player: " << getName() << std::endl;
    std::cout << "Class: " << getClassType() << std::endl;
    std::cout << "HP: " << getHealth() << std::endl;
    std::cout << "Strength: " << getStrength() << std::endl;
    std::cout << "Armor Class: " << getArmorClass() << std::endl;
    std::cout << "Attack Bonus: " << getAttackBonus() << std::endl;
    std::cout << "Dodge Value: " << getDodgeValue() << std::endl;
    std::cout << "--- Traits ---" << std::endl;
    std::cout << "  Strength:     " << traits.strength << std::endl;
    std::cout << "  Agility:      " << traits.agility << std::endl;
    std::cout << "  Speed:        " << traits.speed << std::endl;
    std::cout << "  Intelligence: " << traits.intelligence << std::endl;
}

Character Character::createFromConsole() {
    std::string name;
    std::string classType;
    int choice;

    // --- Name input ---
    std::cout << "Enter your character's name: ";
    std::cin >> name;

    // --- Class selection ---
    std::cout << "\nChoose your class:" << std::endl;
    std::cout << "  1. Warrior  (High strength, tough fighter)" << std::endl;
    std::cout << "  2. Mage     (High intelligence, magic attacks)" << std::endl;
    std::cout << "  3. Rogue    (High agility, fast and sneaky)" << std::endl;
    std::cout << "Choice (1-3): ";

    while (true) {
        std::cin >> choice;
        if (choice == 1) { classType = "Warrior"; break; }
        else if (choice == 2) { classType = "Mage";    break; }
        else if (choice == 3) { classType = "Rogue";   break; }
        else std::cout << "Invalid choice. Enter 1, 2, or 3: ";
    }

    // Base stats per class
    int strength, health, armorClass;
    if (classType == "Warrior") { strength = 10; health = 30; armorClass = 14; }
    else if (classType == "Mage") { strength = 5;  health = 20; armorClass = 10; }
    else { strength = 7;  health = 25; armorClass = 12; }

    Character c(name, classType, strength, health, armorClass);

    std::cout << "\n--- Character Created! ---" << std::endl;
    c.displayCharacter();

    return c;
}