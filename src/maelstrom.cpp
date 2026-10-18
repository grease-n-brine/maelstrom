#include "maelstrom.hpp"

namespace maelstrom {

Maelstrom::Maelstrom(std::string path, char key) 
    : path(std::move(path)), key(key) {}

bool Maelstrom::run_engine() const {
    return true;
}

} // namespace maelstrom