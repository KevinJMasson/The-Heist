#include <vector>
#include <string>
#include "Player.h"
#include "LocationList.h"
#include "Item.h"
#include "gtest/gtest.h"


TEST(TestPlayer, constructor) {
LocationList* ll = new LocationList;
Player* p = new Player(ll);
EXPECT_EQ(p->getState(), 0);
EXPECT_EQ(p->getLocation()->getName().compare("Outside"), 0);
EXPECT_EQ(p->getInventory().size(), 0);
delete p;
delete ll;
}
TEST(TestPlayer, setStateTest) {
LocationList* ll = new LocationList;
Player* p = new Player(ll);
EXPECT_TRUE(p->setState(1));
EXPECT_FALSE(p->setState(3));
EXPECT_FALSE(p->setState(-1));
delete p;
delete ll;
}
TEST(TestPlayer, setLocationTest) {
  LocationList* ll = new LocationList;
  Player* p = new Player(ll);
  EXPECT_EQ(p->getLocation()->getName(), "Outside");
  p->setLocation(ll->getLocation("BACK ROOM"));
  EXPECT_EQ(p->getLocation()->getName(), "Back Room");
  delete p;
  delete ll;
}
TEST(TestPlayer, ItemsTest) {
  LocationList* ll = new LocationList;
  Player* p = new Player(ll);
  p->setLocation(ll->getLocation("GALLERY"));
  std::string Finn = "FINN";
  std::string test = "";
  Key1* key = new Key1;
  p->addItem(key);
  EXPECT_EQ(p->getInventory().size(), 1);
  p->addItem(nullptr);
  EXPECT_EQ(p->getInventory().size(), 1);
  Item* door = new Item("DOOR");
  EXPECT_TRUE(p->useItemOn(p->getInventory().at(0), door));
  EXPECT_EQ(p->getInventory().size(), 0);
  Bone* b = new Bone;
  p->addItem(b);
  p->removeItem(nullptr);
  EXPECT_EQ(p->getInventory().size(), 1);
  p->removeItem(b);
  EXPECT_EQ(p->getInventory().size(), 0);
  Bone* b1 = new Bone;
  p->addItem(b1);
  EXPECT_FALSE(p->useItemOn(p->getInventory().at(0), test));
  EXPECT_EQ(p->getInventory().size(), 1);
  EXPECT_TRUE(p->useItemOn(p->getInventory().at(0), Finn));
  EXPECT_EQ(p->getInventory().size(), 0);
  delete door;
  delete p;
  delete ll;
}
