#ifndef GAME_H
#define GAME_H

#include"ItemList.h"
#include"TextStream.h"

class Item;
class ItemList;
class Location;
class LocationList;
class Player;
class TextStream;

/**
* Starts the game and interfaces with the user
*/

class Game{
 public:
  /**
  * Default Constructor
  */
  Game();
/**
*descrustor
*/
  ~Game();

  /**
  * Starts the game process and gets input from the user
  */
  void playGame();

  /**
  * Contains all of the help suggestions for the user
  */
  void help(Player*, LocationList*);

 private:
  TextStream* textStream;
};
#endif // GAME_H
