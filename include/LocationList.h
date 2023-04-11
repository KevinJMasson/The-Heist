#ifndef LOCATIONLIST_H
#define LOCATIONLIST_H

#include"Location.h"
#include<string>
#include<map>
#include"Item.h"

class Location;
class Item;


/**
* Contains all of the locations in the game
*/

class LocationList{
 public:
  /**
  * Default Constructor
  */
  LocationList();
  /**
  * Destructor
  */
  ~LocationList();

  /**
  * Gets a location
  * @param a string that is the name of the loocation
  * @return a pointer to a location
  */
  Location* getLocation(std::string);

  std::map<std::string, Location*> getAllLocs();

 private:
  std::map<std::string, Location*> locations;
};
#endif // LOCATIONLIST_H
