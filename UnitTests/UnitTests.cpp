#include "pch.h"
#include "CppUnitTest.h"
#include "Character.h"
#include "../Enemy.h"
#include "../Goblin.h"
#include "../Orc.h"
#include "../Dragon.h"
#include "../CombatSystem.h"
#include "../Dice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// =============================================
// CHARACTER TESTS - Ngoc Thanh Thi Nguyen
// =============================================
namespace CharacterTests
{
    TEST_CLASS(DefaultConstructorTests)
    {
    public:
        TEST_METHOD(DefaultClass_IsWarrior)
        {
            Character c;
            Assert::AreEqual(std::string("Warrior"), c.getClassType());
        }
        TEST_METHOD(DefaultCharacter_IsAlive)
        {
            Character c;
            Assert::IsTrue(c.isAlive());
        }
        TEST_METHOD(DefaultCharacter_IsWarrior)
        {
            Character c;
            Assert::IsTrue(c.isWarrior());
        }
    };

    TEST_CLASS(WarriorTests)
    {
    public:
        TEST_METHOD(Warrior_NameIsSet)
        {
            Character c("Thor", "Warrior", 10, 30, 14);
            Assert::AreEqual(std::string("Thor"), c.getName());
        }
        TEST_METHOD(Warrior_IsWarrior)
        {
            Character c("Thor", "Warrior", 10, 30, 14);
            Assert::IsTrue(c.isWarrior());
        }
        TEST_METHOD(Warrior_IsNotMage)
        {
            Character c("Thor", "Warrior", 10, 30, 14);
            Assert::IsFalse(c.isMage());
        }
        TEST_METHOD(Warrior_IsNotRogue)
        {
            Character c("Thor", "Warrior", 10, 30, 14);
            Assert::IsFalse(c.isRogue());
        }
        TEST_METHOD(Warrior_HPIsCorrect)
        {
            Character c("Thor", "Warrior", 10, 30, 14);
            Assert::AreEqual(30, c.getHealth());
        }
        TEST_METHOD(Warrior_AttackBonusGreaterThanZero)
        {
            Character c("Thor", "Warrior", 10, 30, 14);
            Assert::IsTrue(c.getAttackBonus() > 0);
        }
        TEST_METHOD(Warrior_TraitsStrengthGreaterThanZero)
        {
            Character c("Thor", "Warrior", 10, 30, 14);
            Assert::IsTrue(c.getTraits().strength > 0);
        }
    };

    TEST_CLASS(MageTests)
    {
    public:
        TEST_METHOD(Mage_IsMage)
        {
            Character c("Merlin", "Mage", 5, 20, 10);
            Assert::IsTrue(c.isMage());
        }
        TEST_METHOD(Mage_AttackBonusGreaterThanZero)
        {
            Character c("Merlin", "Mage", 5, 20, 10);
            Assert::IsTrue(c.getAttackBonus() > 0);
        }
        TEST_METHOD(Mage_IntelligenceGreaterThanZero)
        {
            Character c("Merlin", "Mage", 5, 20, 10);
            Assert::IsTrue(c.getTraits().intelligence > 0);
        }
    };

    TEST_CLASS(RogueTests)
    {
    public:
        TEST_METHOD(Rogue_IsRogue)
        {
            Character c("Shadow", "Rogue", 7, 25, 12);
            Assert::IsTrue(c.isRogue());
        }
        TEST_METHOD(Rogue_DodgeValueGreaterThanArmorClass)
        {
            Character c("Shadow", "Rogue", 7, 25, 12);
            Assert::IsTrue(c.getDodgeValue() > c.getArmorClass());
        }
        TEST_METHOD(Rogue_AgilityGreaterThanZero)
        {
            Character c("Shadow", "Rogue", 7, 25, 12);
            Assert::IsTrue(c.getTraits().agility > 0);
        }
    };

    TEST_CLASS(DamageTests)
    {
    public:
        TEST_METHOD(TakeDamage_HPReducedCorrectly)
        {
            Character c("Test", "Warrior", 10, 30, 14);
            c.takeDamage(10);
            Assert::AreEqual(20, c.getHealth());
        }
        TEST_METHOD(TakeDamage_StillAliveAfterPartialDamage)
        {
            Character c("Test", "Warrior", 10, 30, 14);
            c.takeDamage(10);
            Assert::IsTrue(c.isAlive());
        }
        TEST_METHOD(TakeDamage_HPIsZeroAfterFatalDamage)
        {
            Character c("Test", "Warrior", 10, 30, 14);
            c.takeDamage(30);
            Assert::AreEqual(0, c.getHealth());
        }
        TEST_METHOD(TakeDamage_IsDeadAfterFatalDamage)
        {
            Character c("Test", "Warrior", 10, 30, 14);
            c.takeDamage(30);
            Assert::IsFalse(c.isAlive());
        }
    };

    TEST_CLASS(InvalidClassTests)
    {
    public:
        TEST_METHOD(InvalidClass_IsNotValid)
        {
            Character c("Unknown", "Knight", 5, 20, 10);
            Assert::IsFalse(c.isValidClassType());
        }
        TEST_METHOD(InvalidClass_AttackBonusIsZero)
        {
            Character c("Unknown", "Knight", 5, 20, 10);
            Assert::AreEqual(0, c.getAttackBonus());
        }
    };
}

// =============================================
// MONSTER TESTS
// =============================================
namespace MonsterTests
{
    TEST_CLASS(GoblinTests)
    {
    public:
        TEST_METHOD(Goblin_NameIsGoblin)
        {
            Goblin g;
            Assert::AreEqual(std::string("Goblin"), g.getName());
        }
        TEST_METHOD(Goblin_HPIsCorrect)
        {
            Goblin g;
            Assert::AreEqual(15, g.getHealth());
        }
        TEST_METHOD(Goblin_StrengthIsCorrect)
        {
            Goblin g;
            Assert::AreEqual(6, g.getStrength());
        }
        TEST_METHOD(Goblin_IsAlive)
        {
            Goblin g;
            Assert::IsTrue(g.isAlive());
        }
        TEST_METHOD(Goblin_TakeDamage)
        {
            Goblin g;
            g.takeDamage(5);
            Assert::AreEqual(10, g.getHealth());
        }
        TEST_METHOD(Goblin_IsDeadAfterFatalDamage)
        {
            Goblin g;
            g.takeDamage(15);
            Assert::IsFalse(g.isAlive());
        }
    };

    TEST_CLASS(OrcTests)
    {
    public:
        TEST_METHOD(Orc_NameIsOrc)
        {
            Orc o;
            Assert::AreEqual(std::string("Orc"), o.getName());
        }
        TEST_METHOD(Orc_HPIsCorrect)
        {
            Orc o;
            Assert::AreEqual(25, o.getHealth());
        }
        TEST_METHOD(Orc_StrengthIsCorrect)
        {
            Orc o;
            Assert::AreEqual(10, o.getStrength());
        }
        TEST_METHOD(Orc_IsAlive)
        {
            Orc o;
            Assert::IsTrue(o.isAlive());
        }
        TEST_METHOD(Orc_StrongerThanGoblin)
        {
            Orc o;
            Goblin g;
            Assert::IsTrue(o.getStrength() > g.getStrength());
        }
    };

    TEST_CLASS(DragonTests)
    {
    public:
        TEST_METHOD(Dragon_NameIsDragon)
        {
            Dragon d;
            Assert::AreEqual(std::string("Dragon"), d.getName());
        }
        TEST_METHOD(Dragon_HPIsCorrect)
        {
            Dragon d;
            Assert::AreEqual(50, d.getHealth());
        }
        TEST_METHOD(Dragon_StrengthIsCorrect)
        {
            Dragon d;
            Assert::AreEqual(20, d.getStrength());
        }
        TEST_METHOD(Dragon_IsAlive)
        {
            Dragon d;
            Assert::IsTrue(d.isAlive());
        }
        TEST_METHOD(Dragon_StrongestMonster)
        {
            Dragon d;
            Orc o;
            Goblin g;
            Assert::IsTrue(d.getStrength() > o.getStrength());
            Assert::IsTrue(d.getStrength() > g.getStrength());
        }
    };
}

// =============================================
// COMBAT TESTS
// =============================================
namespace CombatTests
{
    TEST_CLASS(AttackHitsTests)
    {
    public:
        TEST_METHOD(AttackHits_ReturnsTrueWhenRollPlusBonusMeetsAC)
        {
            CombatSystem cs;
            Assert::IsTrue(cs.attackHits(10, 5, 14));  // 10+5=15 >= 14
        }
        TEST_METHOD(AttackHits_ReturnsFalseWhenRollPlusBonusBelowAC)
        {
            CombatSystem cs;
            Assert::IsFalse(cs.attackHits(5, 3, 14));  // 5+3=8 < 14
        }
        TEST_METHOD(AttackHits_ReturnsTrueWhenExactlyMeetsAC)
        {
            CombatSystem cs;
            Assert::IsTrue(cs.attackHits(10, 4, 14));  // 10+4=14 == 14
        }
    };

    TEST_CLASS(CalculateDamageTests)
    {
    public:
        TEST_METHOD(CalculateDamage_NeverBelowOne)
        {
            CombatSystem cs;
            Assert::IsTrue(cs.calculateDamage(0, 0) >= 1);
        }
        TEST_METHOD(CalculateDamage_IncreasesWithBasePower)
        {
            CombatSystem cs;
            Assert::IsTrue(cs.calculateDamage(10, 8) > cs.calculateDamage(1, 8));
        }
        TEST_METHOD(CalculateDamage_IncreasesWithRoll)
        {
            CombatSystem cs;
            Assert::IsTrue(cs.calculateDamage(5, 20) > cs.calculateDamage(5, 4));
        }
    };

    TEST_CLASS(RunCombatTests)
    {
    public:
        TEST_METHOD(RunCombat_PlayerWinsAgainstWeakEnemy)
        {
            Character player("Hero", "Warrior", 10, 100, 14);
            Goblin enemy;
            Dice dice(20);
            CombatSystem cs;
            bool result = cs.runCombat(player, enemy, dice);
            Assert::IsTrue(result);  // player should win with 100 HP vs Goblin 15 HP
        }
        TEST_METHOD(RunCombat_EnemyDefeatedAfterCombat)
        {
            Character player("Hero", "Warrior", 10, 100, 14);
            Goblin enemy;
            Dice dice(20);
            CombatSystem cs;
            cs.runCombat(player, enemy, dice);
            Assert::IsFalse(enemy.isAlive());
        }
    };
}