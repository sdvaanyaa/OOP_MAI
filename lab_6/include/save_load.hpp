#include "factory.hpp"

// save npcs to file
void save(const set_t &npcs, const std::string &filename);

// load npcs from file
set_t load(const std::string &filename, Factory &factory);