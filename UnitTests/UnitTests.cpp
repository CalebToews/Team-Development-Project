#include "pch.h"
#include "CppUnitTest.h"
#include "Character.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// =============================================
// CHARACTER TESTS - Kristen
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


