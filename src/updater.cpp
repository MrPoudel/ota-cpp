#include "ota/updater.h"
#include <iostream>
namespace ota {
bool Updater::applyUpdateFromManifest(const std::string &path) {
    std::cout << "Applying update from " << path << std::endl;
    return true;
}
}
