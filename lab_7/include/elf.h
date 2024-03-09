#pragma once

#include "npc.h"
#include "dragon.h"
#include "knight.h"

class Elf : public NPC
{
    public:
        Elf(int x, int y);
        Elf(std::istream& is);
        virtual ~Elf() = default;

        int getDistMove() override;
        int getDistFight() override;

        bool accept(std::shared_ptr<NPC> visitor) override;
        bool visit(std::shared_ptr<Knight> monster) override;

        void print() override;
        void print(std::ostream &os) override;   
    protected:
        int dist_move = 10;
        int dist_fight = 50;
};
