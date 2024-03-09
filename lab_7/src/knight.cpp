#include "knight.h"

Knight::Knight(int x, int y) : NPC(KnightType, x, y) {}

Knight::Knight(std::istream& is) : NPC(KnightType, is) {}

int Knight::getDistMove()
{
    return dist_move;
}

int Knight::getDistFight()
{
    return dist_fight;
}

bool Knight::accept(std::shared_ptr<NPC> visitor) 
{
    return visitor->visit(std::shared_ptr<Knight>(this,[](Knight*){}));
}

bool Knight::visit(std::shared_ptr<Dragon> monster) 
{
    if (win()) 
    {
        notify(std::shared_ptr<Knight>(this,[](Knight*){}), monster);
        return true;
    }
    return false;
}

void Knight::print() {
    std::cout << *this;
}

void Knight::print(std::ostream &os) {
    os << *this;
}