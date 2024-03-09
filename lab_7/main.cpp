#include "declaration.h"
#include "npc.h"
#include "dragon.h"
#include "knight.h"
#include "elf.h"
#include "observerConsole.h"
#include "observerFile.h"
#include "factory.h"
#include "fight.h"

std::mutex mtx;

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    

    std::set<std::shared_ptr<NPC>> array; 

    int n = 1;
    for (std::size_t i = 0; i < 50; ++i)
    {
        array.insert(factory(NpcType(std::rand() % 3 + 1),
                            std::rand() % 100,
                            std::rand() % 100));
        ++n;
    }

    ObserverConsole obc;
    ObserverFile obv;

    for (auto &monster : array)
    {
        monster->subscribe(std::make_shared<ObserverConsole>(obc));
        monster->subscribe(std::make_shared<ObserverFile>(obv));
    }

    const int MAX_X{100};
    const int MAX_Y{100};
    bool stop = false;

    std::thread fight_thread(std::ref(FightManager::get(&mtx)));

    std::thread move_thread([&array, &MAX_X, &MAX_Y, &stop]()
    {
        time_t start_time = time(0);

        while (time(0) - start_time <= STOP)
        {
            {
                std::lock_guard<std::mutex> lock(mtx);
                for (std::shared_ptr<NPC> npc : array)
                {
                        if(npc->isAlive()){
                            int distMove = npc->getDistMove();
                            int shift_x = (std::rand() % distMove) * (std::rand() % 3 - 1);
                            int shift_y;
                            if (shift_x >= 0) shift_y = (distMove - shift_x) * (std::rand() % 3 - 1);
                            else shift_y = (distMove + shift_x) * (std::rand() % 3 - 1);
                            npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                        }
                }
                for (std::shared_ptr<NPC> npc : array)
                    for (std::shared_ptr<NPC> other : array)
                        if (other != npc)
                            if (npc->isAlive())
                            if (other->isAlive())
                            if (npc->isClose(other)){
                                FightManager::get(&mtx).add_event({npc, other});
                            }
                
            }
            std::this_thread::sleep_for(30ms);
        }
        
        stop = true;
    });

    while (true)
    {
        if (stop) break;

        {   
            std::lock_guard<std::mutex> lock(mtx);
            const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
            std::array<char, grid * grid> fields{0};
            for (std::shared_ptr<NPC> npc : array)
            {
                auto [x, y] = npc->position();
                int i = x / step_x;
                int j = y / step_y;
                if (i >= grid) --i;
                if (j >= grid) --j;
                
                if (npc->isAlive())
                {
                    switch (npc->getIntType())
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
            }

        
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
    };

    move_thread.join();
    fight_thread.join();

    std::cout << std::endl;

    int count = 0;
    for (auto &monster : array)
    {
        if (monster->isAlive())
        {
            std::cout << *monster;
            ++count;
        }
    }

    std::cout << "Survivors: " << count << std::endl;

    return 0;
}