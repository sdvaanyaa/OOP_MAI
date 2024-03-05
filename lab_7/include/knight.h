#pragma once
#include "npc.h"

struct Knight : public NPC
{
private:
    const int shift_x{30};
    const int shift_y{30};
    const int attack_distance{10};
public:
    Knight(int x, int y);
    Knight(std::istream &is);
    void print() override;
    void save(std::ostream &os) const override;
    bool fight(std::shared_ptr<Dragon> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    friend std::ostream &operator<<(std::ostream &os, Knight &knight);

    std::pair<int, int> get_shift_distance() const override;
    int get_attack_distance() const override;

    bool accept(std::shared_ptr<NPC> visitor) override;
};