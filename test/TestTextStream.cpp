#include "TextStream.h"
#include "gtest/gtest.h"

TEST(TestTextStream, fixText) {
TextStream t;
EXPECT_EQ(t.fixText("lower"), "LOWER");
}
