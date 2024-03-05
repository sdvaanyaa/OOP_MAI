#include "../include/dragon.hpp"
#include "../include/knight.hpp"
#include "../include/elf.hpp"

Dragon::Dragon(int x, int y, std::string name) : NPC(DragonType, x, y, name) {}
Dragon::Dragon(std::istream &is) : NPC(DragonType, is) {}

bool Dragon::accept(std::shared_ptr<NPC> visitor) 
{
    return visitor->visit(std::make_shared<Dragon>(*this));
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

void Dragon::save(std::ostream &os) 
{
    os << DragonType << std::endl;
    NPC::save(os);
}

void Dragon::print(std::ostream &os) 
{
    os << *this << std::endl;
}

std::ostream &operator<<(std::ostream &os, Dragon &dragon)
{
    os << "dragon: " << *static_cast<NPC *>(&dragon);
    return os;
}