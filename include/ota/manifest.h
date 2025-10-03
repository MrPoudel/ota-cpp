#pragma once
#include <string>

namespace ota {
struct Manifest {
    std::string version;
    std::string image;
    std::string signature;
};
}
