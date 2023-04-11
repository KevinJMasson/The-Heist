#include"Player.h"
#include<string>
#include<vector>
#include"LocationList.h"
#include"Location.h"
#include"Item.h"
#include<iostream>

enum states {ALIVE, DEAD, WIN};

Player::Player(LocationList* l) {
  state = ALIVE;
  GameLocs = l;
  currentLocation = GameLocs->getLocation("OUTSIDE");
}

Player::~Player() {
  for (unsigned int i = 0; i < inventory.size(); i++) {
        delete inventory[i];
    }
    inventory.clear();
}

int Player::getState() {
  return state;
}

bool Player::setState(int s) {
  if (s < 3 && s >= 0) {
    state = s;
    return true;
  } else {
    std::cout << "ERROR: Not a valid state\n";
    return false;
  }
}

std::vector<Usable*> Player::getInventory() {
  return inventory;
}

Location* Player::getLocation() {
  return currentLocation;
}

void Player::setLocation(Location* l) {
  currentLocation = l;
}

bool Player::useItemOn(Usable* lh, Item* rh) {
  if (lh->useOn(rh, this)) {
    removeItem(lh);
    return true;
  } else {
    return false;
  }
}

bool Player::useItemOn(Usable* lh, std::string rh) {
  if (lh->useOn(rh, this)) {
    removeItem(lh);
    return true;
  } else {
    return false;
  }
}

void Player::addItem(Usable* i) {
  if (i != nullptr) {
    inventory.push_back(i);
    if (i->getName().compare("PAINTING") == 0)
      setState(2);
    }
}

void Player::removeItem(Usable* i) {
  if (i != nullptr) {
    for (unsigned int j = 0; j < inventory.size(); ++j) {
      if (inventory[j]->getName().compare(i->getName()) == 0) {
        delete inventory[j];
        inventory.erase(inventory.begin()+j);
      }
    }
  }
}

LocationList* Player::getGameLocs() {
  return GameLocs;
}
