#include "../include/npc.hpp"
#include "../include/dragon.hpp"
#include "../include/knight.hpp"
#include "../include/elf.hpp"
#include "../include/observer.hpp"  
#include "../include/factory.hpp"  
#include "../include/save_load.hpp"  

int main(int argc, char **argv)
{
    set_t npcs; 

    Factory factory = Factory(CoutObserver::get());

    std::cout << "Generating ..." << std::endl;

    for (size_t i = 0; i < 10; ++i)
        npcs.insert(factory.produce(NpcType(std::rand() % 3 + 1),
                             std::rand() % 100,
                             std::rand() % 100, 
                             "npc" + std::to_string(i)));
    std::cout << "Saving ..." << std::endl;

    save(npcs, "npc.txt");

    std::cout << "Loading ..." << std::endl;
    npcs = load("npc.txt", factory);

    std::cout << "Fighting ..." << std::endl;
    

    for (size_t distance = 20; (distance <= 100) && !npcs.empty(); distance += 10)
    {
        auto dead_list = fight(npcs, distance);
        for (auto &d : dead_list)
            npcs.erase(d);
        std::cout << "---------- Fight stats ----------" << std::endl
                  << "distance: " << distance << std::endl
                  << "killed: " << dead_list.size() << std::endl
                  << std::endl << std::endl;

    }

    if (npcs.empty())
        std::cout << "All dead ☠️" << std::endl;
    else
        std::cout << "Survivors: " << npcs;

    return 0;
}