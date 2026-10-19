#include "maelstrom.hpp"
#include "exceptions.hpp"
#include <fstream>
#include <vector>
#include <iostream>

namespace maelstrom {

Maelstrom::Maelstrom(std::string path, char key) 
    : path(std::move(path)), key(key) {}

bool Maelstrom::run_engine() const {
    std::ifstream inFile(path, std::ios::binary);

    if (!inFile) {
        throw FileOpenException("Failed to open file: " + path);
        return false;
    }

    std::streamsize size = inFile.seekg(0, std::ios::end).tellg();
    inFile.seekg(0, std::ios::beg);
    std::vector<char> buffer(size);

    if (!inFile.read(buffer.data(), size)) {
        throw FileReadException("Failed to read file: " + path);
        return false;
    }

    inFile.close();

    for (char &byte : buffer) {
        byte ^= key;
    }

    std::ofstream outFile(path, std::ios::binary);

    if (!outFile) {
        throw FileWriteException("Failed to open file for writing: " + path);
        return false;
    }
    if (!outFile.write(buffer.data(), size)) {
        throw FileWriteException("Failed to write file: " + path);
        return false;
    }
    
    outFile.write(buffer.data(), size);
    outFile.close();

    // Process the buffer as needed
    return true;
}

} // namespace maelstrom