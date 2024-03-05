#pragma once
#include "npc.hpp"
#include "dragon.hpp"
#include "knight.hpp"
#include "elf.hpp"
#include <memory>

class Factory
{
private:
    std::shared_ptr<IFightObserver> observer;
public:
    Factory(std::shared_ptr<IFightObserver> observer);

    // default observer is cout
    Factory();

    std::shared_ptr<NPC> produce(std::istream &is);
    std::shared_ptr<NPC> produce(NpcType type, int x, int y, std::string name);
};