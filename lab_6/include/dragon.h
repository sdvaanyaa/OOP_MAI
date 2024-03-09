#pragma once
#include "npc.h"
#include "knight.h"
#include "elf.h"
#include "observer.h"

class DragonVisitor : public Visitor {
    virtual bool visit(const std::shared_ptr<Dragon>&) override;
    virtual bool visit(const std::shared_ptr<Knight>&) override;
    virtual bool visit(const std::shared_ptr<Elf>&) override;
};

class Dragon : public NPC
{   public:
        Dragon(std::string name, int x, int y);
        Dragon(std::istream &is);

        bool accept(std::shared_ptr<Visitor>& visitor, std::shared_ptr<NPC> attacker) override;
        void print() override;
        void print(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Dragon &dragon);
};