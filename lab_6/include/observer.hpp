#pragma once
#include "npc.hpp"

class CoutObserver : public IFightObserver
{
private:
    CoutObserver(){};   
public:
    static std::shared_ptr<IFightObserver> get();

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override;
};

class LogObserver : public IFightObserver
{
    const std::string logFileName = "log.txt";
private:
    LogObserver();
    ~LogObserver();
    std::ofstream fs;
public:
    static std::shared_ptr<IFightObserver> get();

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override;
};