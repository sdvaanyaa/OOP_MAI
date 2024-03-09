#include "elf.h"
#include "dragon.h"
#include "knight.h"

Elf::Elf(std::string name, int x, int y) : NPC(ElfType, name, x, y) {}
Elf::Elf(std::istream &is) : NPC(ElfType, is) {}

void Elf::print() {
    std::cout << *this;
}

void Elf::print(std::ostream &os) {
    os << *this;
}

bool ElfVisitor::visit(const std::shared_ptr<Knight>& other) 
{
    return true;
}

bool Elf::accept(std::shared_ptr<Visitor>& visitor, std::shared_ptr<NPC> attacker)
{
    std::shared_ptr<Elf> self = std::dynamic_pointer_cast<Elf>(shared_from_this());
    if (!self) {
         throw std::runtime_error("dynamic_pointer_cast failed");
    }
    if (visitor -> visit(self)) 
        attacker -> fight_notify(self);
    return visitor -> visit(self);
}

std::ostream &operator<<(std::ostream &os, Elf &elf)
{
    os << "elf " << elf.get_name() << ": " << *static_cast<NPC *>(&elf) << std::endl;
    return os;
}