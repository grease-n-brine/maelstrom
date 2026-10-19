#include "maelstrom.hpp"
#include <fstream>
#include <vector>
#include <iostream>

namespace maelstrom {

Maelstrom::Maelstrom(std::string path, char key) 
    : path(std::move(path)), key(key) {}

bool Maelstrom::run_engine() const {
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file: " << path << std::endl;
        return false;
    }

    std::vector<char> buffer((std::istreambuf_iterator<char>(file)),
                             std::istreambuf_iterator<char>());

    for (auto &c : buffer) {
        c ^= key;
    }

    // Process the buffer as needed
    return true;
}

} // namespace maelstrom