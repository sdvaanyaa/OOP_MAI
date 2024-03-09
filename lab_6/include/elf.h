#pragma once
#include "npc.h"
#include "dragon.h"
#include "knight.h"
#include "observer.h"

class ElfVisitor : public Visitor {
    virtual bool visit(const std::shared_ptr<Knight>&);
};
class Elf : public NPC
{
    public:
        Elf(std::string name, int x, int y);
        Elf(std::istream &is);

        bool accept(std::shared_ptr<Visitor>& visitor, std::shared_ptr<NPC> attacker) override;
        void print() override;
        void print(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Elf &elf);
};