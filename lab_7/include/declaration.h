#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <set>
#include <memory>
#include <mutex>
#include <sstream>
#include <thread>
#include <shared_mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>

#define fileOutput "log.txt"
#define STOP 30

using namespace std::chrono_literals;

extern std::shared_mutex print_mutex;

enum NpcType 
{
    Unknown = 0,
    DragonType = 1,
    KnightType = 2, 
    ElfType = 3 
};

class Observer;

class ObserverConsole;
class ObserverFile;


class NPC;

class Dragon;
class Knight;
class Elf;