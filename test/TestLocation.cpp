#include "Location.h"
#include <string>
#include <vector>
#include "Item.h"
#include "gtest/gtest.h"


TEST(TestLocation, constructorTest) {
    Location l(false, "GALLERY", "FINN");
    EXPECT_FALSE(l.isUnlocked());
    EXPECT_EQ("GALLERY", l.getName());
    EXPECT_EQ("FINN", l.getCharacter());
}

TEST(TestLocation, isUnlocked) {
    Location l(false, "GALLERY", "FINN");
    EXPECT_FALSE(l.isUnlocked());
    l.unlock();
    EXPECT_TRUE(l.isUnlocked());
}

TEST(TestLocation, getName) {
    Location l(false, "GALLERY", "FINN");
    EXPECT_EQ("GALLERY", l.getName());
    EXPECT_NE("VAULT", l.getName());
    EXPECT_NE("YRELLAG", l.getName());
}

TEST(TestLocation, addItem) {
    Location l(false, "GALLERY", "FINN");
    EXPECT_TRUE(l.addItem(new Bone));
}

TEST(TestLocation, removeItem) {
    Location l(false, "GALLERY", "FINN");
    Bone* b = new Bone;
    l.addItem(b);
    l.removeItem(b);
    EXPECT_EQ(0, l.getItems().size());
}

TEST(TestLocation, getItems) {
    Location l(false, "GALLERY", "FINN");
    Bone* b = new Bone;
    l.addItem(b);
    std::vector<Item*> locItems = l.getItems();
    EXPECT_EQ(1, locItems.size());
}

TEST(TestLocation, getCharacter) {
    Location l(false, "GALLERY", "FINN");
    EXPECT_EQ("FINN", l.getCharacter());
    EXPECT_NE("BOB", l.getCharacter());
    EXPECT_NE("NNIF", l.getCharacter());
}

TEST(TestLocation, unlock) {
    Location l(false, "GALLERY", "FINN");
    EXPECT_FALSE(l.isUnlocked());
    l.unlock();
    EXPECT_TRUE(l.isUnlocked());
}
