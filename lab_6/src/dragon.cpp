#include "dragon.h"
#include "knight.h"
#include "elf.h"

Dragon::Dragon(std::string name, int x, int y) : NPC(DragonType, name, x, y) {}
Dragon::Dragon(std::istream &is) : NPC(DragonType, is) {}

void Dragon::print() {
    std::cout << *this;
}

void Dragon::print(std::ostream &os) {
    os << *this;
}

bool DragonVisitor::visit(const std::shared_ptr<Elf>& other) 
{
    return true;
}

bool DragonVisitor::visit(const std::shared_ptr<Knight>& other) 
{
    return true;
}

bool DragonVisitor::visit(const std::shared_ptr<Dragon>& other) 
{
    return true;
}

bool Dragon::accept(std::shared_ptr<Visitor>& visitor, std::shared_ptr<NPC> attacker)
{
    std::shared_ptr<Dragon> self = std::dynamic_pointer_cast<Dragon>(shared_from_this());
    if (!self) {
        throw std::runtime_error("dynamic_pointer_cast failed");
    }
    if (visitor -> visit(self)) 
        attacker -> fight_notify(self);
    return visitor -> visit(self);
}

std::ostream &operator<<(std::ostream &os, Dragon &dragon)
{
    os << "dragon " << dragon.get_name() << ": " << *static_cast<NPC *>(&dragon) << std::endl;
    return os;
}