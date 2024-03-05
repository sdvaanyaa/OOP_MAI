#pragma once
#include "npc.hpp"

struct Knight : public NPC
{
    Knight(int x, int y, std::string name);
    Knight(std::istream &is);

    bool accept(std::shared_ptr<NPC> visitor) override;
    
    bool fight(std::shared_ptr<Dragon> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Elf> other) override;

    void save(std::ostream &os) override;
    void print(std::ostream &os) override;
    
    friend std::ostream &operator<<(std::ostream &os, Knight &knight);
};