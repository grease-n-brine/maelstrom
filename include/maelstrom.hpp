#ifndef MAELSTROM_HPP
#define MAELSTROM_HPP

#include <string>

namespace maelstrom {
class Maelstrom {
public:
    Maelstrom(std::string path, char key);
    bool run_engine() const;
private:
    std::string path;
    char key;
};
} // namespace maelstrom

#endif // MAELSTROM_HPP