#include <gtest/gtest.h>
#include "ota/manifest.h"

TEST(ManifestTest, ParseValid) {
    ota::Manifest m;
    ASSERT_TRUE(m.loadFromFile("valid.json"));
    EXPECT_EQ(m.version(), "1.0");
}
