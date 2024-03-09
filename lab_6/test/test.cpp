#include <gtest/gtest.h>
#include <cstring>
#include "npc.h"
#include "dragon.h"
#include "knight.h"
#include "elf.h"
#include "observer.h"
#include "factory.h"
#include "battle.h"

std::unordered_map<NpcType, std::shared_ptr<Visitor>> visitors = {
        {DragonType, std::make_shared<DragonVisitor>()},
        {KnightType, std::make_shared<KnightVisitor>()},
        {ElfType, std::make_shared<ElfVisitor>()}
};


TEST(Test_Dragon, Constructor) {
    std::string name {"default"};
    Dragon dragon(name, 1, 1);
    EXPECT_TRUE(dragon.get_name() == name && dragon.get_type() == DragonType and dragon.get_x() == 1 and dragon.get_y() == 1);
}

TEST(Test_Knight, Constr)
{
    std::string name {"default"};
    Knight knight(name, 1, 1);
    EXPECT_TRUE(knight.get_name() == name && knight.get_type() == KnightType and knight.get_x() == 1 and knight.get_y() == 1);
}

TEST(Test_Elf, Constr) {
    std::string name {"default"};
    Elf elf(name, 1, 1);
    EXPECT_TRUE(elf.get_name() == name && elf.get_type() == ElfType and elf.get_x() == 1 and elf.get_y() == 1);
}

TEST(Test_Dragon, FightDragon)
{
    std::string name {"default"};
    std::shared_ptr<Dragon> dragon1 = std::make_shared<Dragon>(name, 1, 1);
    std::shared_ptr<Dragon> dragon2 = std::make_shared<Dragon>(name, 1, 2);
    EXPECT_TRUE(dragon1 -> accept(visitors[dragon2 -> get_type()], dragon2) == true);
}

TEST(Test_NPC, Distance) {
    std::string name {"default"};
    std::shared_ptr<Elf> elf1 = std::make_shared<Elf>(name, 0, 1);
    std::shared_ptr<Elf> elf2 = std::make_shared<Elf>(name, 1, 1);
    std::size_t distance = 5;
    EXPECT_TRUE(elf1 -> is_close(elf2, distance));
}

TEST(Test_Factory, CreateNPC) {
    std::string name {"default"};
    std::shared_ptr<NPC> dragon = Create(DragonType, name,  1, 1);
    EXPECT_TRUE(dragon -> get_name() == name && dragon -> get_type() == DragonType and dragon -> get_x() == 1 and dragon -> get_y() == 1);
}

TEST(Test_Fight, FightKnightWithElf) {
    std::string name {"default"};
    std::shared_ptr<Knight> knight = std::make_shared<Knight>(name, 1, 2);
    std::shared_ptr<Elf> elf = std::make_shared<Elf>(name, 1, 1);
    std::set<std::shared_ptr<NPC>> monsters {elf, knight};
    std::set<std::shared_ptr<NPC>> corpse {knight};
    std::set<std::shared_ptr<NPC>> dead_list = battle(monsters, 10);
    ASSERT_EQ(corpse, dead_list);
}

TEST(Test_Fight, FightKnightWithDragon) {
    std::string name {"default"};
    std::shared_ptr<Knight> knight = std::make_shared<Knight>(name, 1, 2);
    std::shared_ptr<Dragon> dragon = std::make_shared<Dragon>(name, 1, 1);
    std::set<std::shared_ptr<NPC>> monsters {dragon, knight};
    std::set<std::shared_ptr<NPC>> corpse {dragon, knight};
    std::set<std::shared_ptr<NPC>> dead_list = battle(monsters, 10);
    ASSERT_EQ(corpse, dead_list);
}

TEST(Test_NPC, InsertObservers) {
    std::string name {"default"};
    std::shared_ptr<Elf> elf = std::make_shared<Elf>(name, 1, 2);
    std::shared_ptr<Knight> knight = std::make_shared<Knight>(name, 2, 1);
    ObserverConsole observer;
    std::shared_ptr observer1 = std::make_shared<ObserverConsole>(observer);
    elf -> subscribe(observer1);
    knight -> subscribe(observer1);
    EXPECT_TRUE(knight -> accept(visitors[elf -> get_type()], elf) == true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}