#include "../include/observer.hpp"
#include <fcntl.h>

std::shared_ptr<IFightObserver> CoutObserver::get(){
    static CoutObserver instance;
    return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
}

void CoutObserver::on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win)
{
    if (win)
    {
        std::cout << std::endl << "-------- Murder --------" << std::endl;
        attacker->print(std::cout);
        std::cout << ">kill  " << std::endl;
        defender->print(std::cout);
    }
}

LogObserver::LogObserver(){
    fs = std::ofstream(logFileName);
    if (!fs.is_open()){
        throw std::runtime_error("field to open log file");
    }
}

LogObserver::~LogObserver(){
    fs.flush();
    fs.close();
}

std::shared_ptr<IFightObserver> LogObserver::get(){
    static LogObserver instance;

    return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
}

void LogObserver::on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win)
{
    if (win)
    {
        fs << std::endl << "-------- Murder --------" << std::endl;
        attacker->print(fs);
        std::cout << ">kill  " << std::endl;
        defender->print(fs);
    }
}