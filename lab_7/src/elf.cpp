#include "../include/elf.h"
#include "../include/dragon.h"
#include "../include/knight.h"

Elf::Elf(int x, int y) : NPC(ElfType, x, y) {}
Elf::Elf(std::istream &is) : NPC(ElfType, is) {}

bool Elf::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Elf>(this,[](Elf*){}));
}

void Elf::print()
{
    std::cout << *this;
}

void Elf::save(std::ostream &os) const
{
    os << ElfType << std::endl;
    NPC::save(os);
}

std::pair<int, int> Elf::get_shift_distance() const
{
    return {shift_x, shift_y};
}

int Elf::get_attack_distance() const {
    return attack_distance;
}

bool Elf::fight(std::shared_ptr<Dragon> other)
{
    fight_notify(other, false);
    return false;
}

bool Elf::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, true);
    return true;
}

bool Elf::fight(std::shared_ptr<Elf> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Elf &knight)
{
    os << "elf: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}