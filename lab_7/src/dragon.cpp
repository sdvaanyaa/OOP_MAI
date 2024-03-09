#include "dragon.h"

Dragon::Dragon(int x, int y) : NPC(DragonType, x, y) {}

Dragon::Dragon(std::istream &is) : NPC(DragonType, is) {}

int Dragon::getDistMove()
{
    return dist_move;
}

int Dragon::getDistFight()
{
    return dist_fight;
}

bool Dragon::accept(std::shared_ptr<NPC> visitor) 
{
    return visitor->visit(std::shared_ptr<Dragon>(this,[](Dragon*){}));
}

bool Dragon::visit(std::shared_ptr<Dragon> monster) 
{
    if (win()) 
    {
        notify(std::shared_ptr<Dragon>(this,[](Dragon*){}), monster);
        return true;
    }
    return false;
}
bool Dragon::visit(std::shared_ptr<Knight> monster) 
{
    if (win()) 
    {
        notify(std::shared_ptr<Dragon>(this,[](Dragon*){}), monster);
        return true;
    }
    return false;
}
bool Dragon::visit(std::shared_ptr<Elf> monster) 
{
    if (win()) 
    {
        notify(std::shared_ptr<Dragon>(this,[](Dragon*){}), monster);
        return true;
    }
    return false;
}

void Dragon::print() {
    std::cout << *this;
}

void Dragon::print(std::ostream &os) {
    os << *this;
}
