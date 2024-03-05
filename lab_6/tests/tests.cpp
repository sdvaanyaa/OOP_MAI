#include <gtest/gtest.h>
#include <string>
#include <memory>
#include "../include/npc.hpp"
#include "../include/knight.hpp"
#include "../include/elf.hpp"
#include "../include/dragon.hpp"
#include "../include/factory.hpp"
#include "../include/observer.hpp"

TEST(NPCInteractions, test1) {
    std::shared_ptr<NPC> dragon = std::make_shared<Dragon>(0, 0, "dragon");
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(1, 1, "knight");

    bool murder1 = dragon->accept(knight);
    bool murder2 = knight->accept(dragon);
    ASSERT_TRUE(murder1);
    ASSERT_TRUE(murder2);
}

TEST(NPCInteractions, test2) {
    std::shared_ptr<NPC> dragon = std::make_shared<Dragon>(0, 0, "dragon");
    std::shared_ptr<NPC> elf = std::make_shared<Elf>(0, 0, "elf");

    bool murder1 = dragon->accept(elf);
    bool murder2 = elf->accept(dragon);
    ASSERT_FALSE(murder1);
    ASSERT_TRUE(murder2);
}

TEST(NPCInteractions, test3) {
    std::shared_ptr<NPC> dragon1 = std::make_shared<Dragon>(0, 0, "dragon1");
    std::shared_ptr<NPC> dragon2 = std::make_shared<Dragon>(1, 1, "dragon2");

    bool murder = dragon1->accept(dragon2);
    ASSERT_TRUE(murder);
}

TEST(NPCInteractions, test4) {
    std::shared_ptr<NPC> knight1 = std::make_shared<Knight>(0, 0, "knight1");
    std::shared_ptr<NPC> knight2 = std::make_shared<Knight>(1, 1, "knight2");

    bool murder = knight1->accept(knight2);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test5) {
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(0, 0, "knight");
    std::shared_ptr<NPC> elf = std::make_shared<Elf>(1, 1, "elf");

    bool murder1 = knight->accept(elf);
    bool murder2 = elf->accept(knight);
    ASSERT_TRUE(murder1);
    ASSERT_FALSE(murder2);
}

TEST(NPCInteractions, test6) {
    std::shared_ptr<NPC> elf1 = std::make_shared<Elf>(0, 0, "elf1");
    std::shared_ptr<NPC> elf2 = std::make_shared<Elf>(1, 1, "elf2");

    bool murder = elf1->accept(elf2);
    ASSERT_FALSE(murder);
}

TEST(ObserverTests, test) {
    std::shared_ptr<NPC> elf = std::make_shared<Elf>(0, 0, "elf");
    std::shared_ptr<NPC> dragon = std::make_shared<Dragon>(1, 1, "dragon");
    
    dragon->subscribe(CoutObserver::get());
    elf->subscribe(CoutObserver::get());
    
    testing::internal::CaptureStdout();
    elf->accept(dragon);
    std::string output = testing::internal::GetCapturedStdout();
    
    testing::internal::CaptureStdout();
    std::cout << std::endl << "-------- Murder --------" << std::endl;  
    dragon->print(std::cout);
    std::cout << ">kill  " << std::endl;
    elf->print(std::cout);
    std::string answer = testing::internal::GetCapturedStdout();
    
    ASSERT_TRUE(output == answer);
}

TEST(SaveTest, test){
    std::shared_ptr<NPC> dragon = std::make_shared<Dragon>(0, 0, "dragon");
    
    testing::internal::CaptureStdout();
    dragon->save(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    
    testing::internal::CaptureStdout(); 
    std::cout << DragonType << std::endl;
    std::cout << dragon.get()->x << std::endl;
    std::cout << dragon.get()->y << std::endl;
    std::cout << dragon.get()->name << std::endl;
    std::string answer = testing::internal::GetCapturedStdout();
    
    ASSERT_TRUE(output == answer);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}