#include "../include/save_load.hpp"

// save npcs to file
void save(const set_t &npcs, const std::string &filename)
{
    std::ofstream fs(filename);
    fs << npcs.size() << std::endl;
    for (auto &n : npcs)
        n->save(fs);
    fs.flush();
    fs.close();
}

// load npcs from file
set_t load(const std::string &filename, Factory &factory)
{
    set_t result;
    std::ifstream is(filename);
    if (is.good() && is.is_open()) 
    {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(factory.produce(is));
        is.close();
    }
    else
        std::cerr << "Error: " << std::strerror(errno) << std::endl;

    return result;
}