#include <gtest/gtest.h>
#include "declaration.h"
#include "npc.h"
#include "dragon.h"
#include "knight.h"
#include "elf.h"
#include "factory.h"
#include "observerConsole.h"
#include "observerFile.h"

TEST(Test_Dragon, Constr)
{
    Dragon Dragon{1, 1};
    EXPECT_TRUE(Dragon.getType() == "DragonType");
}

TEST(Test_Knight, Constr)
{
    std::shared_ptr<Knight> knight = std::make_shared<Knight>(1, 2);
    EXPECT_TRUE(knight->getType() == "KnightType");
}

TEST(Test_Elf, Constr)
{
    std::shared_ptr<Elf> elf = std::make_shared<Elf>(1, 1);
    EXPECT_TRUE(elf->getType() == "ElfType");
}

TEST(Test_Elf, FightKnight)
{
    std::shared_ptr<Knight> knight = std::make_shared<Knight>(1, 1);
    std::shared_ptr<Elf> elf = std::make_shared<Elf>(1, 2);
    EXPECT_TRUE(knight->accept(elf) == true);
}

TEST(Test_Knight, FightKnight)
{
    std::shared_ptr<Knight> Knight1 = std::make_shared<Knight>(1, 1);
    std::shared_ptr<Knight> Knight2 = std::make_shared<Knight>(1, 2);
    EXPECT_TRUE(Knight1->accept(Knight2) == false && Knight2->accept(Knight1) == false);
}

TEST(Test_NPC, Distance)
{
    std::shared_ptr<Elf> Elf1 = std::make_shared<Elf>(1, 1);
    std::shared_ptr<Elf> Elf2 = std::make_shared<Elf>(7, 9);
    float distance = 10.0;
    EXPECT_TRUE(Elf1->distance(Elf2) == distance);
}

TEST(Test_NPC, InsertObservers)
{
    Elf elf{1, 1};
    ObserverConsole observer;
    elf.subscribe(std::make_shared<ObserverConsole>(observer));
    EXPECT_TRUE(elf.countObservers() == 1);
}

TEST(Test_NPC, Alive)
{
    std::shared_ptr<Knight> knight = std::make_shared<Knight>(1, 1);
    EXPECT_TRUE(knight->isAlive() == true);
    knight->must_die();
    EXPECT_TRUE(knight->isAlive() == false);
}

TEST(Test_NPC, EraseObservers)
{
    Dragon dragon{1, 1};
    ObserverFile observer;
    std::shared_ptr observer1 = std::make_shared<ObserverFile>(observer);
    dragon.subscribe(observer1);
    dragon.unsubscribe(observer1);
    EXPECT_TRUE(dragon.countObservers() == 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}