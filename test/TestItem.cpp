#include <iostream>
#include <string>
#include "Item.h"
#include "Location.h"
#include "LocationList.h"
#include "Player.h"
#include "gtest/gtest.h"


TEST(TestItem, constructorTest) {
Bone* b = new Bone;
EXPECT_EQ(b->getName(), "BONE");
delete b;
}
TEST(TestItem, useOnItem) {
LocationList* l = new LocationList;
Player* p = new Player(l);
p->setLocation(l->getLocation("GALLERY"));
Key1* key = new Key1;
Item* door = new Item("DOOR");
Bone* i = new Bone;
EXPECT_FALSE(i->useOn("", p));
EXPECT_TRUE(i->useOn("FINN", p));
EXPECT_TRUE(key->useOn(door, p));
delete key;
delete door;
delete i;
delete p;
delete l;
}

TEST(TestItem, testFail) {
  LocationList* l = new LocationList;
  Player* p = new Player(l);
  p->setLocation(l->getLocation("ENTRYWAY"));
  Coin* c = new Coin;
  Knife* k = new Knife;
  Item* i = new Item("FAKE PAINTING");
  EXPECT_TRUE(c->useOn("GUARD", p));
  EXPECT_EQ(p->getState(), 1);
  p->setState(0);
  EXPECT_TRUE(k->useOn("GUARD", p));
  EXPECT_EQ(p->getState(), 1);
  p->setLocation(l->getLocation("SHOWCASE"));
  p->setState(0);
  EXPECT_TRUE(k->useOn(i, p));
  EXPECT_EQ(p->getState(), 1);
  delete p;
  delete l;
  delete c;
  delete k;
  delete i;
}
