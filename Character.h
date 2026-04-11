#pragma once
#include "Entity.h"
#include "Traits.h"
#include <string>

class Character : public Entity {
private:
    std::string classType;
    Traits traits;

public:
    Character();
    Character(std::string name, std::string classType, int strength, int health, int armorClass);

    std::string getClassType() const;
    void setClassType(std::string classType);

    Traits getTraits() const;

    int getAttackBonus() const;
    int getDodgeValue() const;

    bool isWarrior() const;
    bool isMage() const;
    bool isRogue() const;

    bool isValidClassType() const;

    void displayCharacter() const;
};