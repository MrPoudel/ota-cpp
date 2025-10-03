#pragma once
#include <string>
#include <functional>

namespace ota {

enum class Status {
    OK,
    VERIFY_FAIL,
    WRITE_FAIL,
    ACTIVATE_FAIL,
    HEALTH_FAIL
};

struct UpdaterConfig {
    std::string activeSlot;
    std::string inactiveSlot;
    std::string pubkeyPath;
    unsigned int healthTimeoutSec = 30;
};

class Updater {
public:
    explicit Updater(const UpdaterConfig& cfg);
    ~Updater();

    Status applyUpdateFromManifest(const std::string& manifestPath,
                                   std::function<void(int)> progressCb = nullptr);

    Status confirmUpdate();
    Status rollback();

    std::string currentSlot() const;
    std::string candidateSlot() const;

private:
    UpdaterConfig config_;
};

} // namespace ota
