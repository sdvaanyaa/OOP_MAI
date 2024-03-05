#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>
#include <shared_mutex>

// type for npcs
struct NPC;
struct Dragon;
struct Knight;
struct Elf;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType
{
    Unknown = 0,
    DragonType = 1,
    KnightType = 2,
    ElfType = 3
};

struct IFightObserver
{
    virtual void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) = 0;
};

class NPC
{
protected:
    std::mutex mtx;

    NpcType type;
    int x{0};
    int y{0};
    const int shift_x{0};
    const int shift_y{0};
    const int attack_distance{0};
    bool alive{true};

    std::vector<std::shared_ptr<IFightObserver>> observers;

public:
    NPC(NpcType t, int _x, int _y);
    NPC(NpcType t, std::istream &is);

    void subscribe(std::shared_ptr<IFightObserver> observer);
    void fight_notify(const std::shared_ptr<NPC> defender, bool win);
    virtual bool is_close(const std::shared_ptr<NPC> &other);

    virtual bool accept(std::shared_ptr<NPC> visitor) = 0;
    // visit
    virtual bool fight(std::shared_ptr<Dragon> other) = 0;
    virtual bool fight(std::shared_ptr<Knight> other) = 0;
    virtual bool fight(std::shared_ptr<Elf> other) = 0;

    virtual void print() = 0;
    std::pair<int, int> position();
    NpcType get_type();

    virtual void save(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);

    void move(int max_x, int max_y);

    virtual std::pair<int, int> get_shift_distance() const = 0;
    virtual int get_attack_distance() const = 0;

    bool is_alive();
    void must_die();
};