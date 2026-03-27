#pragma once
#include "Entity.h"
#include <string>

class Enemy : public Entity {
private:
    std::string enemyType;

public:
    Enemy();
    Enemy(const std::string& name, const std::string& enemyType, int strength, int health, int armorClass);

    std::string getEnemyType() const;
    void setEnemyType(const std::string& enemyType);

    int getAttackPower() const;
    void displayEnemy() const;
};