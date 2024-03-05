#include "../include/npc.h"
#include "../include/dragon.h"
#include "../include/knight.h"
#include "../include/elf.h"
#include <sstream>

#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <vector>
#include <optional>

using namespace std::chrono_literals;

std::mutex print_mutex;

std::atomic<bool> stop_move_thread(false);
std::atomic<bool> stop_fight_thread(false);

const std::chrono::milliseconds fightManagerSleep = 250ms; 
const std::chrono::milliseconds moveManagerSleep = 1s; 

// Text Observer
class TextObserver : public IFightObserver
{
private:
    TextObserver(){};

public:
    static std::shared_ptr<IFightObserver> get()
    {
        static TextObserver instance;
        return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override
    {
        if (win)
        {
            std::lock_guard<std::mutex> lck(print_mutex);
            std::cout << std::endl
                      << "-------- Murder --------" << std::endl;
            attacker->print();
            defender->print();
        }
    }
};

struct FightEvent
{
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager
{
private:
    std::queue<FightEvent> events;
    std::shared_mutex mtx;

    FightManager() {}

public:
    static FightManager &get()
    {
        static FightManager instance;
        return instance;
    }

    void add_event(FightEvent &&event)
    {
        std::lock_guard<std::shared_mutex> lock(mtx);
        events.push(event);
    }

    void operator()()
    {
        while (!stop_fight_thread)
        {
            {
                std::optional<FightEvent> event;

                {
                    std::lock_guard<std::shared_mutex> lock(mtx);
                    if (!events.empty())
                    {
                        event = events.back();
                        events.pop();
                    }
                }

                if (event)
                {
                    try
                    {
                        if (event->attacker->is_alive())     // no zombie fighting!
                            if (event->defender->is_alive()) // already dead!
                                if (event->defender->accept(event->attacker))
                                {
                                    // std::cout << "serve event" << std::endl;
                                    event->defender->must_die();
                                }
                    }
                    catch (...)
                    {
                        std::lock_guard<std::shared_mutex> lock(mtx);
                        events.push(*event);
                    }
                }
                else
                    std::this_thread::sleep_for(fightManagerSleep);
            }
        }
    }
};

std::shared_ptr<NPC> factory(NpcType type, int x, int y) {
    std::shared_ptr<NPC> result;
    switch (type) {
    case ElfType:
        result = std::make_shared<Elf>(x, y);
        break;
    case KnightType:
        result = std::make_shared<Knight>(x, y);
        break;
    case DragonType:
        result = std::make_shared<Dragon>(x, y);
        break;
    default:
        break;
    }
    if (result)
        result->subscribe(TextObserver::get());

    return result;
}

// print to screen
std::ostream &operator<<(std::ostream &os, const set_t &array)
{
    for (auto &n : array){
        if (n->is_alive()){
            n->print();
        }
    }
    return os;
}

int main()
{
    std::time_t currentTime = std::time(nullptr);
    std::time_t endTime = currentTime + 30;

    set_t array; // монстры

    const int MAX_X{20};
    const int MAX_Y{20};

    // Гененрируем начальное распределение монстров
    std::cout << "----- Generating  -----" << std::endl;
    size_t count_npc = 50;
    for (size_t i = 0; i < count_npc; ++i)
        array.insert(factory(NpcType(std::rand() % 3 + 1),
                             std::rand() % MAX_X,
                             std::rand() % MAX_Y));

    std::cout << "----- Starting list -----" << std::endl
              << array;

    std::thread fight_thread(std::ref(FightManager::get()));

    std::thread move_thread([&array, MAX_X, MAX_Y]()
                            {
            while (!stop_move_thread)
            {
                // move phase
                for (std::shared_ptr<NPC> npc : array)
                {
                        if(npc->is_alive()){
                            npc->move(MAX_X, MAX_Y);
                        }
                }
                // lets fight
                for (std::shared_ptr<NPC> npc : array)
                    for (std::shared_ptr<NPC> other : array)
                        if (other != npc)
                            if (npc->is_alive())
                            if (other->is_alive())
                            if (npc->is_close(other)){
                                FightManager::get().add_event({npc, other});
                                // std::cout << "add event: " << *npc << " @ " << *other << std::endl;
                            }

                std::this_thread::sleep_for(moveManagerSleep);
            } });

    while (currentTime < endTime)
    {
        const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
        {
            std::vector<char> fields(grid*grid);
            for (std::shared_ptr<NPC> npc : array)
            {
                auto [x, y] = npc->position();
                int i = x / step_x;
                int j = y / step_y;

                if (npc->is_alive())
                {
                    switch (npc->get_type())
                    {
                    case DragonType:
                        fields[i + grid * j] = 'D';
                        break;
                    case KnightType:
                        fields[i + grid * j] = 'K';
                        break;
                    case ElfType:
                        fields[i + grid * j] = 'E';
                        break;

                    default:
                        break;
                    }
                }
                else
                    fields[i + grid * j] = '.';
            }

            std::lock_guard<std::mutex> lck(print_mutex);
            for (int j = 0; j < grid; ++j)
            {
                for (int i = 0; i < grid; ++i)
                {
                    char c = fields[i + j * grid];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(1s);
        currentTime = std::time(nullptr);
    };

    stop_fight_thread = true;
    stop_move_thread = true;

    fight_thread.join();
    move_thread.join();

    std::cout << " ----- Final list  -----" << std::endl
              << array;

    return 0;
}