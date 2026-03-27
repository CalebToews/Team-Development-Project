#pragma once
#include "Character.h"
#include "Enemy.h"
#include "Dice.h"

class CombatSystem {
public:
    CombatSystem();

    bool attackHits(int roll, int attackBonus, int targetArmorClass) const;
    int calculateDamage(int basePower, int roll) const;

    void playerAttack(Character& player, Enemy& enemy, Dice& dice);
    void enemyAttack(Enemy& enemy, Character& player, Dice& dice);

    bool runCombat(Character& player, Enemy& enemy, Dice& dice);
};
