#ifndef LOCATION_H
#define LOCATION_H

#include<vector>
#include<string>
#include"Item.h"
#include"TextStream.h"


class Item;
class TextStream;

/**
* Class containg the room a character is in
*/

class Location{
 public:
  /**
  *Default Constructor
  * @param a bool as to whether the room is unlocked or not
  * @param a string for the name of the location
  * @param a string for the name of the character in the location
  */
  Location(bool, std::string, std::string);

  ~Location();

  /**
  * Checks to see if the room is accessible
  * @return whether or not the room is unlocked
  */
  bool isUnlocked();

  /**
  * Trys to add an item to the room
  * @param an item that will try to be added
  * @return whether or not the item was successfully added
  */
  bool addItem(Item*);

  /**
  * Trys to remove an item from the room
  * @param an item that will try to be removed
  * @return whether or not the item was successfully removed
  */
  bool removeItem(Item*);

  Item* findItem(std::string);

  /**
  * Gets the items that are in the location
  * @return a vector containing the items in the location
  */
  std::vector<Item*> getItems();

  /**
  * Gets the character that is in the location
  * @return a string containing the name of the character
  */
  std::string getCharacter();

  /**
  * Sets the character that is in the location
  * @param a string containing the name of the character
  */
  void setCharacter(std::string);

  /**
  * Unlocks location
  */
  void unlock();

  /**
  * Gets the name of the location
  * @return the name of the location
  */
  std::string getName();

 private:
  bool unlocked;

  std::string name;

  std::vector<Item*> locItems;

  std::string character;
};
#endif // LOCATION_H
