#include "ota/updater.h"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: otactl apply <manifest.json>\n";
        return 1;
    }

    ota::UpdaterConfig cfg{"A", "B", "/etc/ota/pub.pem"};
    ota::Updater updater(cfg);

    if (std::string(argv[1]) == "apply") {
        auto status = updater.applyUpdateFromManifest(argv[2], [](int p){
            std::cout << "Progress: " << p << "%\n";
        });
        if (status == ota::Status::OK)
            std::cout << "Update applied successfully.\n";
        else
            std::cout << "Update failed.\n";
    }

    return 0;
}
