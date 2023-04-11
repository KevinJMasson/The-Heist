#include "ItemList.h"
#include "gtest/gtest.h"

TEST(TestItemList, getItem) {
ItemList i;
EXPECT_EQ(i.getItem(""), nullptr);
}
