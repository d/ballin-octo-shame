//
// Created by Pivotal Data on 3/23/15.
//

#include "Yo.h"
#include "gtest/gtest.h"

TEST(YoTest, BarIsZero) {
    EXPECT_EQ(0, Yo().Bar());
}