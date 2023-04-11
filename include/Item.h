#ifndef ITEM_H
#define ITEM_H

#include<string>
#include"LocationList.h"
#include"Player.h"

class Player;
class LocationList;

/**
* Abstract class to check if items can interact with one another
*/

class Item {
 public:
 /**
* Default Constructor
*/
  Item(std::string n) : name(n) {}

  virtual ~Item() {}

 /**
 * Gets the name of the item
 * @return The name of the item
 */
  std::string getName();

 protected:
  std::string name;
};

class Usable : public Item {
 public :
 /**
 * Default Constructor
 */
  Usable(std::string n) : Item(n) {}
  /**
  * Checks to see if an item is usable on another item
  * @param a string that contains the name of an item
  * @return whether or not an item is usable on another item
  */
  virtual bool useOn(std::string, Player*);

 /**
 * Checks to see if an item is usable on another item
 * @param an item that contains an item
 * @return whether or not an item is usable on another item
 */
  virtual bool useOn(Item*, Player*);
};

class Bone : public Usable {
 public:
   /**
   * Default constructor, sets name to "BONE".
   */
Bone(): Usable("BONE") {}

virtual bool useOn(std::string, Player*);
};

class Key1 : public Usable {
 public:
   /**
   * Default constructor, sets name to "KEY TO BACK ROOM".
   */
Key1(): Usable("KEY") {}
/**
* Checks to see if an item is usable on another item
* @param an item that contains an item
* @return whether or not an item is usable on another item
*/
virtual bool useOn(Item*, Player*);
};

class Magnet : public Usable {
 public:
  /**
  * Default Constructor
  */
  Magnet() : Usable("MAGNET") {}
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @param pointer to a item object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(Item*, Player* p);
};

class Coin : public Usable {
 public:
/**
* Default Constructor
*/
  Coin() : Usable("COIN") {}
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(std::string, Player*);
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(Item*, Player*);
};

class Pop : public Usable {
 public:
   /**
   * Default Constructor
   */
  Pop() : Usable("POP") {}
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(Item*, Player*);
};

class ToiletPaper : public Usable {
 public:
   /**
   * Default Constructor
   */
  ToiletPaper() : Usable("TOILET PAPER") {}
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(std::string, Player*);
};

class Plunger : public Usable {
 public:
   /**
   * Default Constructor
   */
  Plunger() : Usable("PLUNGER") {}
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(std::string, Player*);
};

class Hammer : public Usable {
 public:
   /**
   * Default Constructor
   */
  Hammer() : Usable("HAMMER") {}
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(Item*, Player*);
};

class MirrorFragment : public Usable {
 public:
   /**
   * Default Constructor
   */
  MirrorFragment() : Usable("MIRROR FRAGMENT") {}
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(Item*, Player*);
};

class Keycard : public Usable {
 public:
   /**
   * Default Constructor
   */
  Keycard() : Usable("KEYCARD") {}
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(Item*, Player*);
};

class Hairspray : public Usable {
 public:
   /**
   * Default Constructor
   */
  Hairspray() : Usable("HAIRSPRAY") {}
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(Item*, Player*);
};

class LaxativePop : public Usable {
 public:
   /**
   * Default Constructor
   */
  LaxativePop() : Usable("LAXATIVE POP") {}
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(std::string, Player*);
};

class Screwdriver : public Usable {
 public:
  Screwdriver() : Usable("SCREWDRIVER") {}
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(Item*, Player*);
};
class AccessCodes : public Usable {
 public:
   /**
   * Default Constructor
   */
  AccessCodes() : Usable("ACCESS CODES") {}

  virtual bool useOn(Item*, Player*);
};

class Knife : public Usable {
 public:
   /**
   * Default Constructor
   */
  Knife() : Usable("KNIFE") {}
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(std::string, Player*);
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(Item*, Player*);
};

class IceCream : public Usable {
 public:
  /**
  * Default Constructor
  */
  IceCream() : Usable("ICE CREAM") {}
  /**
  * Checks to see if an item is usable on another item
  * @param Pointer to a Player object
  * @return boolean whether or not an item is usable on another item
  */
  virtual bool useOn(std::string, Player*);
};

#endif // ITEM_H
