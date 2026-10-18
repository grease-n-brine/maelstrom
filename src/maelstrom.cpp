#include "maelstrom.hpp"
#include <fstream>
#include <vector>
#include <iostream>

namespace maelstrom {

Maelstrom::Maelstrom(std::string path, char key) 
    : path(std::move(path)), key(key) {}

bool Maelstrom::run_engine() const {
    return true;
}

} // namespace maelstrom