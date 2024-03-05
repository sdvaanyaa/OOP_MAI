#include "../include/knight.h"
#include "../include/elf.h"
#include "../include/dragon.h"

Knight::Knight(int x, int y) : NPC(KnightType, x, y) {}
Knight::Knight(std::istream &is) : NPC(KnightType, is) {}

void Knight::print()
{
    std::cout << *this;
}

bool Knight::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Knight>(this,[](Knight*){}));
}

void Knight::save(std::ostream &os) const
{
    os << KnightType << std::endl;
    NPC::save(os);
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

std::ostream &operator<<(std::ostream &os, Knight &knight)
{
    os << "knight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}

std::pair<int, int> Knight::get_shift_distance() const
{
    return {shift_x, shift_y};
}

int Knight::get_attack_distance() const {
    return attack_distance;
}