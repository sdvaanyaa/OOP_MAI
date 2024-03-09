#include "dragon.h"
#include "knight.h"
#include "elf.h"

Knight::Knight(std::string name, int x, int y) : NPC(KnightType, name, x, y) {}
Knight::Knight(std::istream &is) : NPC(KnightType, is) {}

void Knight::print() {
    std::cout << *this;
}

void Knight::print(std::ostream &os) {
    os << *this;
}

bool Knight::accept(std::shared_ptr<Visitor>& visitor, std::shared_ptr<NPC> attacker) {
    std::shared_ptr<Knight> self = std::dynamic_pointer_cast<Knight>(shared_from_this());
    if (!self) {
         throw std::runtime_error("dynamic_pointer_cast failed");
    }
    if (visitor -> visit(self)) 
        attacker -> fight_notify(self);
    return visitor -> visit(self);
}

bool KnightVisitor::visit(const std::shared_ptr<Dragon>& other)
{
    return true;
}

std::ostream &operator<<(std::ostream &os, Knight &knight)
{
    os << "knight " << knight.get_name() << ": " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}