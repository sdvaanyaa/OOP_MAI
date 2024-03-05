#include "../include/knight.hpp"
#include "../include/elf.hpp"
#include "../include/dragon.hpp"

Knight::Knight(int x, int y, std::string name) : NPC(KnightType, x, y, name) {}
Knight::Knight(std::istream &is) : NPC(KnightType, is) {}

bool Knight::accept(std::shared_ptr<NPC> visitor) 
{
    return visitor->visit(std::make_shared<Knight>(*this));
}

bool Knight::fight(std::shared_ptr<Dragon> other)
{
    fight_notify(other, true);
    return true;
}

bool Knight::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return false;
}

bool Knight::fight(std::shared_ptr<Elf> other)
{
    fight_notify(other, false);
    return false;
}

void Knight::save(std::ostream &os)
{
    os << KnightType << std::endl;
    NPC::save(os);
}

void Knight::print(std::ostream &os) 
{
    os << *this << std::endl;
}

std::ostream &operator<<(std::ostream &os, Knight &knight)
{
    os << "knight: " << *static_cast<NPC *>(&knight);
    return os;
}