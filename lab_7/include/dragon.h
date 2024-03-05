#pragma once
#include "npc.h"

struct Dragon : public NPC
{
private:
    const int shift_x{50};
    const int shift_y{50};
    const int attack_distance{30};
public:
    Dragon(int x, int y);
    Dragon(std::istream &is);

    void print() override;

    bool fight(std::shared_ptr<Dragon> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    bool accept(std::shared_ptr<NPC> visitor) override;

    std::pair<int, int> get_shift_distance() const override;
    int get_attack_distance() const override;

    void save(std::ostream &os) const override;

    friend std::ostream &operator<<(std::ostream &os, Dragon &dragon);
};