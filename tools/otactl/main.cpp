#include "ota/updater.h"
#include <iostream>
int main(int argc, char **argv) {
    ota::Updater updater;
    if (argc > 1) {
        updater.applyUpdateFromManifest(argv[1]);
    } else {
        std::cout << "Usage: otactl <manifest.json>" << std::endl;
    }
}
