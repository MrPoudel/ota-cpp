#include "ota/updater.h"
#include <gtest/gtest.h>

TEST(UpdaterTest, Dummy) {
    ota::Updater updater;
    EXPECT_TRUE(updater.applyUpdateFromManifest("dummy.json"));
    // EXPECT_FALSE(updater.applyUpdateFromManifest("dummy.json"));

}
