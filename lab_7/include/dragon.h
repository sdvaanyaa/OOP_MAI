#pragma once

#include "npc.h"
#include "knight.h"
#include "elf.h"

class Dragon : public NPC 
{
    public:
        Dragon(int x, int y);
        Dragon(std::istream& is);
        virtual ~Dragon() = default;

        int getDistMove() override;
        int getDistFight() override;

        bool accept(std::shared_ptr<NPC> visitor) override;
        bool visit(std::shared_ptr<Dragon> monster) override;
        bool visit(std::shared_ptr<Knight> monster) override;
        bool visit(std::shared_ptr<Elf> monster) override;

        void print() override;
        void print(std::ostream &os) override;

    protected:
        int dist_move = 50;
        int dist_fight = 30;
};