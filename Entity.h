#pragma once
#include <string>

class Entity {
protected:
    std::string name;
    int strength;
    int health;
    int armorClass;

public:
    Entity();
    Entity(std::string name, int strength, int health, int armorClass);

    std::string getName() const;
    int getStrength() const;
    int getHealth() const;
    int getArmorClass() const;

    void setName(std::string name);
    void setStrength(int strength);
    void setHealth(int health);
    void setArmorClass(int armorClass);

    void takeDamage(int damage);
    bool isAlive() const;
};