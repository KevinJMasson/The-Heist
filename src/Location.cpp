#include"Location.h"
#include<string>
#include<vector>
#include"Item.h"
#include<iostream>

Location::Location(bool l = true, std::string n = "", std::string c = "") {
  unlocked = l;
  name = n;
  character = c;
}

Location::~Location() {
  for (int i = 0; i < locItems.size(); i++)
    delete locItems[i];
}

bool Location::isUnlocked() {
  return unlocked;
}

bool Location::addItem(Item* i) {
  locItems.push_back(i);
  return true; //will need to add a fail state
}

bool Location::removeItem(Item* i) {
  //vector<Item*>::iterator it;
  for (unsigned int j = 0; j < locItems.size(); ++j) {
    if (locItems[j]->getName().compare(i->getName()) == 0) {
      delete locItems[j];
      locItems.erase(locItems.begin()+j);
    }
  }
  return true; //will probably want to make a check to see if its still there
}

Item* Location::findItem(std::string n) {
  for (unsigned int i = 0; i < locItems.size(); i++) {
    if (locItems[i]->getName().compare(n) == 0)
      return locItems[i];
    }
  return nullptr;
}

std::vector<Item*> Location::getItems() {
  return locItems;
}

std::string Location::getCharacter() {
  return character;
}

void Location::setCharacter(std::string c) {
  character = c;
}

void Location::unlock() {
  unlocked = true;
}

std::string Location::getName() {
  return name;
}
