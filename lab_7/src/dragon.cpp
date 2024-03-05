#include "../include/dragon.h"
#include "../include/knight.h"
#include "../include/elf.h"

Dragon::Dragon(int x, int y) : NPC(DragonType, x, y) {}
Dragon::Dragon(std::istream &is) : NPC(DragonType, is) {}

bool Dragon::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Dragon>(this,[](Dragon*){}));
}

void Dragon::print()
{
    std::cout << *this;
}


bool Dragon::fight(std::shared_ptr<Dragon> other) 
{
    fight_notify(other, true);
    return true;
}

bool Dragon::fight(std::shared_ptr<Knight> other) 
{
    fight_notify(other, true);
    return true;
}

bool Dragon::fight(std::shared_ptr<Elf> other) 
{
    fight_notify(other, true);
    return true;
}

void Dragon::save(std::ostream &os) const
{
    os << DragonType << std::endl;
    NPC::save(os);
}

int Dragon::get_attack_distance() const {
    return attack_distance;
}

std::pair<int, int> Dragon::get_shift_distance() const
{
    return {shift_x, shift_y};
}

std::ostream &operator<<(std::ostream &os, Dragon &dragon)
{
    os << "dragon: " << *static_cast<NPC *>(&dragon) << std::endl;
    return os;
}