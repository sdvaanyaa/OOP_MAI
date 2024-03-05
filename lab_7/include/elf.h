#pragma once
#include "npc.h"

class Elf : public NPC
{
private:
    const int shift_x{10};
    const int shift_y{10};
    const int attack_distance{50};
public:
    Elf(int x, int y);
    Elf(std::istream &is);

    void print() override;
    void save(std::ostream &os) const override;
    bool fight(std::shared_ptr<Dragon> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    bool accept(std::shared_ptr<NPC> visitor) override;

    std::pair<int, int> get_shift_distance() const override;
    int get_attack_distance() const override;

    friend std::ostream &operator<<(std::ostream &os, Elf &knight);
};