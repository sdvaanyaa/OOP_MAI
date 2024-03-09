#pragma once

#include "npc.h"
#include "dragon.h"
#include "elf.h"

class Knight : public NPC
{
    public:
        Knight(int x, int y);
        Knight(std::istream& is);
        virtual ~Knight() = default;

        int getDistMove() override;
        int getDistFight() override;

        bool accept(std::shared_ptr<NPC> visitor) override;
        bool visit(std::shared_ptr<Dragon> monster) override;

        void print() override;
        void print(std::ostream &os) override;

    protected:
        int dist_move = 30;
        int dist_fight = 10;
};