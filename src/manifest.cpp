#include "ota/manifest.h"
#include <fstream>
#include <nlohmann/json.hpp> // optional if you add JSON dep

using json = nlohmann::json;

namespace ota {

bool Manifest::loadFromFile(const std::string& path) {
    std::ifstream f(path);
    if (!f.is_open()) return false;
    try {
        json j;
        f >> j;
        version_ = j.value("version", "");
    } catch (...) {
        return false;
    }
    return true;
}

std::string Manifest::version() const { return version_; }

} // namespace ota
