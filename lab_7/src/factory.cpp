#include "factory.h"

std::shared_ptr<NPC> factory(NpcType type, int x, int y)
{
    switch (type)
    {
        case DragonType :
            return std::make_shared<Dragon>(x, y);
            break;
        case KnightType :
            return std::make_shared<Knight>(x, y);
            break;
        case ElfType :
            return std::make_shared<Elf>(x, y);
            break;
        default:
            std::cout << "unexpected type : " << type << std::endl;
            break;
    }
    return nullptr;
}

std::shared_ptr<NPC> factory(std::istream &is)
{
    int type;
    is >> type;
    switch (type)
    {
        case DragonType :
            return std::make_shared<Dragon>(is);
            break;
        case KnightType :
            return std::make_shared<Knight>(is);
            break;
        case ElfType :
            return std::make_shared<Elf>(is);
            break;
        default:
            std::cout << "unexpected type : " << type << std::endl;
            break;
    }
    return nullptr;
}