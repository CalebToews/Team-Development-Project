#include "Entity.h"

Entity::Entity() {
    name = "";
    strength = 0;
    health = 0;
    armorClass = 0;
}

Entity::Entity(std::string name, int strength, int health, int armorClass) {
    this->name = name;
    this->strength = strength;
    this->health = health;
    this->armorClass = armorClass;
}

std::string Entity::getName() const {
    return name;
}

int Entity::getStrength() const {
    return strength;
}

int Entity::getHealth() const {
    return health;
}

int Entity::getArmorClass() const {
    return armorClass;
}

void Entity::setName(std::string name) {
    this->name = name;
}

void Entity::setStrength(int strength) {
    this->strength = strength;
}

void Entity::setHealth(int health) {
    this->health = health;
}

void Entity::setArmorClass(int armorClass) {
    this->armorClass = armorClass;
}

void Entity::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

bool Entity::isAlive() const {
    return health > 0;
}