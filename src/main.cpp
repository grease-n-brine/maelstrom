#include "maelstrom.hpp"
#include "exceptions.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <file_path> <key>" << std::endl;
        return 1;
    }

    std::string file_path = argv[1];
    char key = argv[2][0];
    maelstrom::Maelstrom engine(file_path, key);

    try {
        if (!engine.run_engine()) {
            std::cerr << "Failed to process file: " << file_path << std::endl;
            return 1;
        }
    } catch (const maelstrom::FileOpenException &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const maelstrom::FileReadException &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const maelstrom::FileWriteException &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
