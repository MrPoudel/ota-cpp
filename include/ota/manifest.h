#pragma once
#include <string>

namespace ota {

class Manifest {
public:
    bool loadFromFile(const std::string& path);
    std::string version() const;

private:
    std::string version_;
};

} // namespace ota
