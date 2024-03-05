#include "../include/npc.hpp"

NPC::NPC(NpcType t, int _x, int _y, std::string _name) : type(t), x(_x), y(_y), name(_name) {}
NPC::NPC(NpcType t, std::istream &is) : type(t)
{
    is >> x;
    is >> y;
    is >> name;
}

void NPC::subscribe(std::shared_ptr<IFightObserver> observer)
{
   observers.push_back(observer);
}

void NPC::fight_notify(const std::shared_ptr<NPC> defender, bool win)
{
    for (auto &o : observers)
        o->on_fight(shared_from_this(), defender, win);
}

bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance) const
{
    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(distance, 2))
        return true;
    else
        return false;
}

void NPC::save(std::ostream &os)
{
    os << x << std::endl;
    os << y << std::endl;
    os << name << std::endl;
}

std::ostream &operator<<(std::ostream &os, NPC &npc)
{
    os << "{ x:" << npc.x << ", y:" << npc.y << ", name: " << npc.name << " }";
    return os;
}

std::ostream &operator<<(std::ostream &os, const set_t &npcs)
{
    for (auto &n : npcs)
        n->print(os);
    return os;
}

set_t fight(const set_t &npcs, size_t distance)
{
    set_t dead_list;

    for (const auto &attacker : npcs)
        for (const auto &defender : npcs)
            if ((attacker != defender) && (attacker->is_close(defender, distance)))
            {
                bool success{false};
                success = attacker->accept(defender);
                if (success)
                    dead_list.insert(defender);
            }

    return dead_list;
}


bool NPC::visit(std::shared_ptr<Knight> knight) {
    return this->fight(knight);
}

bool NPC::visit(std::shared_ptr<Elf> elf) {
    return this->fight(elf);
}

bool NPC::visit(std::shared_ptr<Dragon> dragon) {
    return this->fight(dragon);
}