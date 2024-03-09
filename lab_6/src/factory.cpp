#include "factory.h"


std::shared_ptr<NPC> Create(NpcType type, std::string name, int x, int y) {
    std::shared_ptr<NPC> hero;
    switch (type) {
        case DragonType:
            hero = std::make_shared<Dragon>(name, x, y);
            break;
        case KnightType:
            hero = std::make_shared<Knight>(name, x, y);
            break;
        case ElfType:
            hero = std::make_shared<Elf>(name, x, y);
            break;
    }
    return hero;
}

std::shared_ptr<NPC> Create(std::istream& stream) {
    std::shared_ptr<NPC> hero;
    int type;
    stream >> type;
    switch(type) {
        case DragonType:
            hero = std::make_shared<Dragon>(stream);
            break;
        case KnightType:
            hero = std::make_shared<Knight>(stream);
            break;
        case ElfType:
            hero = std::make_shared<Elf>(stream);
            break;
    }
    return hero;
}

std::string randname() {
    std::map<int, std::string> name;
    name.insert({0, "Astarion"});
    name.insert({1, "Gale"});
    name.insert({2, "Lae'zel"});
    name.insert({3, "Shadowheart"});
    name.insert({4, "Wyll"});
    name.insert({5, "Baeloth"});
    name.insert({6, "Korga"});
    name.insert({7, "Volo"});
    name.insert({8, "Zevlor"});
    name.insert({9, "Kazador"});

    return name[std::rand() % 10];
}