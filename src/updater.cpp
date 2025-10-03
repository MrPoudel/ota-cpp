#include "ota/updater.h"

namespace ota {

Updater::Updater(const UpdaterConfig& cfg) : config_(cfg) {}
Updater::~Updater() {}

Status Updater::applyUpdateFromManifest(const std::string&, std::function<void(int)>) {
    return Status::OK; // stub
}

Status Updater::confirmUpdate() { return Status::OK; }
Status Updater::rollback() { return Status::OK; }
std::string Updater::currentSlot() const { return config_.activeSlot; }
std::string Updater::candidateSlot() const { return config_.inactiveSlot; }

} // namespace ota
