#ifndef PLAYER_H
#define PLAYER_H

#include"Item.h"
#include<string>
#include"Location.h"
#include<vector>
#include"LocationList.h"


class Item;
class Usable;
class Location;
class LocationList;

/**
* Everything to do with the player including their attributes and
* the functions for using items or moving locaions
*/

class Player {
 public:
  /**
  * Default Constructor, sets the playres current location
  * @param a locationlist of the current location
  */
  Player(LocationList*);

  ~Player();

  /**
  * Gets the current state of a player
  * @return a string of player's current state
  */
  int getState();

  /**
  * Sets the players state
  * @param a string containing the new state
  * @return a bool that determines if the new state is now set
  */
  bool setState(int);

  /**
  * Gets the player's current inventory
  * @return a vector of items the player has
  */
  std::vector<Usable*> getInventory();

  /**
  * Gets the player's current location
  * @return a location of the player's current location
  */
  Location* getLocation();

  /**
  * Sets the players current location
  * @param a location to set the player to
  */
  void setLocation(Location*);

  /**
  * Using an item on an item
  * @param an item that the player wants to use
  * @param an item that the player wants to act upon
  * @return a bool if successful
  */
  bool useItemOn(Usable*, Item*);

  /**
  * Using an item on an character
  * @param an item that the player wants to use
  * @param a character that the player wants to act upon
  * @return a bool if successful
  */
  bool useItemOn(Usable*, std::string);

  /**
  * Adds an item to the inventory
  * @param an item to be added to the inventory
  * @return a bool if successful
  */
  void addItem(Usable*);

  LocationList* getGameLocs();

  /**
  * Removes an item from the inventory
  * @param an item to be removed from the inventory
  * @return a bool if successful
  */
void removeItem(Usable*);

 private:
  int state;

  std::vector<Usable*> inventory;

  Location* currentLocation;

  LocationList* GameLocs;
};
#endif // PLAYER_H
