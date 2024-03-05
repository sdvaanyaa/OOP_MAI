#include "../include/elf.hpp"
#include "../include/dragon.hpp"
#include "../include/knight.hpp"

Elf::Elf(int x, int y, std::string name) : NPC(ElfType, x, y, name) {}
Elf::Elf(std::istream &is) : NPC(ElfType, is) {}

bool Elf::accept(std::shared_ptr<NPC> visitor) 
{
    return visitor->visit(std::make_shared<Elf>(*this));
}

bool Elf::fight(std::shared_ptr<Elf> other)
{
    fight_notify(other, false);
    return false;
}

bool Elf::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, true);
    return true;
}

bool Elf::fight(std::shared_ptr<Dragon> other)
{
    fight_notify(other, false);
    return false;
}

void Elf::save(std::ostream &os)
{
    os << ElfType << std::endl;
    NPC::save(os);
}

void Elf::print(std::ostream &os) 
{
    os << *this << std::endl;
}

std::ostream &operator<<(std::ostream &os, Elf &elf)
{
    os << "elf: " << *static_cast<NPC *>(&elf);
    return os;
}