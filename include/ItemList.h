#ifndef ITEMLIST_H
#define ITEMLIST_H

#include<string>
#include"Item.h"
#include<map>


class Usable;

/**
* Implements a list of all of the items in the game
*/

class ItemList{
 public:
  /**
  * Default Constructor
  */
  ItemList();

  /**
  * Destructor
  */
  ~ItemList();

  /**
  * Gets an item from the list of items
  * @param a string that contains the name of an item
  * @return a pointer to the item or a null pointer
  */
  Usable* getItem(std::string);

 private:
  std::map<std::string, Usable*> items;
};
#endif // ITEMLIST_H
