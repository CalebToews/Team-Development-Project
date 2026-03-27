#pragma once
#include "Entity.h"
#include <string>

class Character : public Entity {
private:
    std::string classType;

public:
    Character();
    Character(std::string name, std::string classType, int strength, int health, int armorClass);

    std::string getClassType() const;
    void setClassType(std::string classType);

    int getAttackBonus() const;
    int getDodgeValue() const;
};
