#pragma once
#include <string>

namespace ota {
class Updater {
public:
    bool applyUpdateFromManifest(const std::string &path);
};
}
