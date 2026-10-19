#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
namespace maelstrom {

class MaelstromException : public std::runtime_error {
public:
    explicit MaelstromException(const std::string &message)
        : std::runtime_error(message) {}
};

class FileOpenException : public MaelstromException {
public:
    explicit FileOpenException(const std::string &message)
        : MaelstromException(message) {}
};

class FileReadException : public MaelstromException {
public:
    explicit FileReadException(const std::string &message)
        : MaelstromException(message) {}
};

class FileWriteException : public MaelstromException {
public:
    explicit FileWriteException(const std::string &message)
        : MaelstromException(message) {}
};

class InvalidKeyException : public MaelstromException {
public:
    explicit InvalidKeyException(const std::string &message)
        : MaelstromException(message) {}
};

} // namespace maelstrom
#endif // EXCEPTIONS_HPP