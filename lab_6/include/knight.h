#pragma once
#include "npc.h"
#include "dragon.h"
#include "elf.h"
#include "observer.h"

class KnightVisitor : public Visitor {
    bool visit(const std::shared_ptr<Dragon>& other) override;
};

class Knight : public NPC
{
    public:
        Knight(std::string name, int x, int y);
        Knight(std::istream &is);

        bool accept(std::shared_ptr<Visitor>& visitor, std::shared_ptr<NPC> attacker) override;
        void print() override;
        void print(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Knight &knight);
};