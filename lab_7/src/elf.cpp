#include "elf.h"

Elf::Elf(int x, int y) : NPC(ElfType, x, y) {}

Elf::Elf(std::istream& is) : NPC(ElfType, is) {}

int Elf::getDistMove()
{
    return dist_move;
}

int Elf::getDistFight()
{
    return dist_fight;
}

bool Elf::accept(std::shared_ptr<NPC> visitor) 
{
    return visitor->visit(std::shared_ptr<Elf>(this,[](Elf*){}));
}

bool Elf::visit(std::shared_ptr<Knight> monster) 
{
    if (win()) 
    {
        notify(std::shared_ptr<Elf>(this,[](Elf*){}), monster);
        return true;
    }
    return false;
}

void Elf::print() {
    std::cout << *this;
}

void Elf::print(std::ostream &os) {
    os << *this;
}
