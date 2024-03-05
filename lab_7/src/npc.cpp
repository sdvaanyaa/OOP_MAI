#include "../include/npc.h"

NPC::NPC(NpcType t, int _x, int _y) : type(t), x(_x), y(_y) {}
NPC::NPC(NpcType t, std::istream &is) : type(t)
{
    is >> x;
    is >> y;
}

void NPC::subscribe(std::shared_ptr<IFightObserver> observer)
{
    observers.push_back(observer);
}

void NPC::fight_notify(const std::shared_ptr<NPC> defender, bool win)
{
    for (auto &o : observers)
        o->on_fight(std::shared_ptr<NPC>(this, [](NPC *) {}), defender, win);
}

bool NPC::is_close(const std::shared_ptr<NPC> &other)
{
    auto [other_x, other_y] = other->position();
    int attack_distance = get_attack_distance();
    std::lock_guard<std::mutex> lck(mtx);
    if ((std::pow(x - other_x, 2) + std::pow(y - other_y, 2)) <= std::pow(attack_distance, 2)){
        // std::cout << "close" << std::endl;
        return true;
    } 
    return false;
}

NpcType NPC::get_type()
{
    std::lock_guard<std::mutex> lck(mtx);
    return type;
}

std::pair<int, int> NPC::position()
{
    std::lock_guard<std::mutex> lck(mtx);
    return {x, y};
}

inline int randShift(int max_shift){
    int randInt = std::rand();

    return (randInt % max_shift) * pow(-1, randInt % 2); 
}

void NPC::move(int max_x, int max_y)
{
    auto [shift_x, shift_y] = get_shift_distance();
    std::lock_guard<std::mutex> lck(mtx);

    shift_x = randShift(shift_x);
    shift_y = randShift(shift_y);

    if ((x + shift_x >= 0) && (x + shift_x <= max_x))
        x += shift_x;
    if ((y + shift_y >= 0) && (y + shift_y <= max_y))
        y += shift_y;
}

void NPC::save(std::ostream &os) const
{
    os << x << std::endl;
    os << y << std::endl;
}

std::ostream &operator<<(std::ostream &os, NPC &npc)
{
    os << "{ x:" << npc.x << ", y:" << npc.y << "} ";
    return os;
}

bool NPC::is_alive()
{
    std::lock_guard<std::mutex> lck(mtx);
    return alive;
}

void NPC::must_die()
{
    std::lock_guard<std::mutex> lck(mtx);
    alive = false;
}