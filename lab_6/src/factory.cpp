#include "../include/factory.hpp"
#include "../include/observer.hpp"

Factory::Factory(std::shared_ptr<IFightObserver> _observer): observer(_observer) {}

Factory::Factory(): observer(CoutObserver::get()) {}

std::shared_ptr<NPC> Factory::produce(std::istream &is){
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type)
    {
        switch (type)
        {
        case DragonType:
            result = std::make_shared<Dragon>(is);
            break;
        case KnightType:
            result = std::make_shared<Knight>(is);
            break;
        case ElfType:
            result = std::make_shared<Elf>(is);
            break;
        }
    }
    else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    if (result)
        result->subscribe(observer);

    return result;
}

std::shared_ptr<NPC> Factory::produce(NpcType type, int x, int y, std::string name){
    std::shared_ptr<NPC> result;
    switch (type)
    {
    case DragonType:
        result = std::make_shared<Dragon>(x, y, name);
        break;
    case KnightType:
        result = std::make_shared<Knight>(x, y, name);
        break;
    case ElfType:
        result = std::make_shared<Elf>(x, y, name);
        break;
    default:
        break;
    }
    if (result)
        result->subscribe(observer);

    return result;
}