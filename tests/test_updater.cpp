#include <gtest/gtest.h>
#include "ota/updater.h"

TEST(UpdaterTest, BasicConfig) {
    ota::UpdaterConfig cfg{"A", "B", "pub.pem"};
    ota::Updater updater(cfg);

    EXPECT_EQ(updater.currentSlot(), "A");
    EXPECT_EQ(updater.candidateSlot(), "B");
}
