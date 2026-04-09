#include "Enemy.h"
#include <iostream>

constexpr int ATTACK_POWER_DIVISOR = 2;

Enemy::Enemy() : Entity() {
    enemyType = "Goblin";
    thac0 = 15;
}

Enemy::Enemy(const std::string& name, const std::string& enemyType, int strength, int health, int armorClass)
    : Entity(name, strength, health, armorClass) {
    this->enemyType = enemyType;
    thac0 = 15;
}

std::string Enemy::getEnemyType() const {
    return enemyType;
}

void Enemy::setEnemyType(const std::string& enemyType) {
    this->enemyType = enemyType;
}

int Enemy::getAttackPower() const {
    return strength / ATTACK_POWER_DIVISOR;
}
 
int Enemy::getTHAC0() const {
    return thac0;
}

void Enemy::displayEnemy() const {
    std::cout << "Enemy: " << getName() << std::endl;
    std::cout << "Type: " << enemyType << std::endl;
    std::cout << "HP: " << getHealth() << std::endl;
    std::cout << "Strength: " << getStrength() << std::endl;
    std::cout << "Armor Class: " << getArmorClass() << std::endl;
    std::cout << "Attack Power: " << getAttackPower() << std::endl;
}