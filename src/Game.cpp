#include"Game.h"
#include"LocationList.h"
#include"Location.h"
#include<iostream>
#include"Player.h"
#include"Item.h"
#include"ItemList.h"
#include"TextStream.h"
#include<string>
#include<vector>
#include<map>
#include<utility>

Game::Game() {
  textStream = new TextStream;
}

Game::~Game() {
  delete textStream;
}

void Game::playGame() {
  std::string input, inVerb, inNoun;
  ItemList* items = new ItemList;
  LocationList* locs = new LocationList;
  Player* user = new Player(locs);
  int inCount;
  std::cout << "Welcome to The Heist!\n";
  std::cout << "You play as Francis Bigglesworth, art collector and "
  "world class thief extraordinaire. Your current caper involves the renowned "
  "art museum: Le Mauvais Gout. Inside this museum holds the great art piece "
  "known worldwide, the Roly Poly Formuoli. In order to pull off this heist, "
  "Francis is going to need to use all his cunning to disable the museum\'s "
  "defenses, overcome obstacles, and get past each guard using his wits and the"
  " help of those around him.\n";
  std::cout << std::endl;
  std::cout << "TO PLAY: Francis can \'GO\' to locations, \'PICKUP\' to pickup"
  "items in the world, \'USE\' to use an item on a character or world item, "
  "\'TALK\' to talk to the characters in the world. Type \'HELP\' to get info "
  "about the game.\n";
  std::cout << std::endl;
  textStream->locationEnter("OUTSIDE");
  std::cout << std::endl;
  do {
    input.clear();
    inNoun.clear();
    inVerb.clear();
    getline(std::cin, input);
    std::cin.clear();
    input = textStream->fixText(input);

    for (inCount = 0; inCount < input.length() && input[inCount] != ' ';
      inCount++)
        inVerb = inVerb += input[inCount];

    for (inCount = inCount+1; inCount < input.length(); inCount++)
      inNoun = inNoun += input[inCount];

    input.clear();

    if (inVerb.compare("HELP") == 0) {
      help(user, locs);
    }

    if (inVerb.compare("GO") == 0) {
      if (locs->getLocation(inNoun) != nullptr) {
        if (locs->getLocation(inNoun)->isUnlocked()) {
          user->setLocation(locs->getLocation(inNoun));
          textStream->locationEnter(inNoun);
        } else {
          std::cout << "That area is not unlocked yet!" << std::endl;
        }
      } else {
        std::cout << "That location does not exist!" << std::endl;
        }
    }

    if (inVerb.compare("TALK") == 0) {
      if (user->getLocation()->getCharacter().compare(inNoun) == 0)
        textStream->characterInteract(inNoun);
      else
        std::cout << "That character does not exist!" << std::endl;
    }

    if (inVerb.compare("USE") == 0) {
      bool hasItem = false;
      for (unsigned int i = 0; i < user->getInventory().size(); i++) {
        if (user->getInventory()[i]->getName().compare(inNoun) == 0) {
          hasItem = true;
        }
      }
      //checks if the user has the item
      if (hasItem) {
        std::string lh = inNoun;
        std::cout << "Who or what would you like to use the item on?\n";
        getline(std::cin, input);
        std::cin.clear();
        input = textStream->fixText(input);
        //check if location has the character
        if (input.compare(user->getLocation()->getCharacter()) == 0) {
          if (user->useItemOn(items->getItem(lh), input)) {
          } else {
            std::cout << "You cannot use that item on that character!"
            << std::endl;
          }
        } else {
          hasItem = false;
          if (user->getLocation()->findItem(input) != nullptr) {
            hasItem = true;
          if (user->useItemOn(items->getItem(lh),
            user->getLocation()->findItem(input))) {
            } else {
              std::cout << "You cannot use that item on that item!\n";
            }
          } else {
            std::cout << "There is no item by that name in this location!\n";
          }
        }
      } else {
        std::cout << "You do not have that item in your inventory.\n";
      }
    }

    if (inVerb.compare("PICKUP") == 0) {
      bool hasItem = false;
      if (user->getLocation()->findItem(inNoun) != nullptr)
        hasItem = true;
      if (hasItem) {
          if (items->getItem(inNoun) != nullptr) {
            user->addItem(items->getItem(inNoun));
            user->getLocation()->removeItem(items->getItem(inNoun));
            std::cout << "The item has been added to your inventory.\n";
          } else {
            std::cout<< "You cannot pick up that item\n";
          }
        } else {
          std::cout << "There is no item by that name in the current room.\n";
        }
      }
    std::cout << std::endl;
  } while (user->getState() == 0);
  if (user->getState() == 2) {
    std::cout << "You have nabbed the painting and escaped successfully! The "
    "world shall know there is no thief greater than "
    "Francis Bigglesworth!\n" << std::endl;
    std::cout << "Thank you for playing our game!";
  } else {
    std::cout << "Rats! You almost had the painting too! Time to go back to the"
    " drawing board and try again!\n" << "GAME OVER\n" << std::endl;
  }
  delete user, locs;
}

void Game::help(Player* u, LocationList* l) {
  int in;
  enum helpOptions {CHARACTERS = 1, ITEMS, LOCATIONS, INVENTORY, DIRECTIONS};
  std::cout << "What do you wish to view:\n";
  std::cout << "1. Character in room\n";
  std::cout << "2. Interactable items in room\n";
  std::cout << "3. Available locations\n";
  std::cout << "4. Current inventory\n";
  std::cout << "5. How to play\n";
  std::cin >> in;

  switch (in) {
    case CHARACTERS: {
      std::cout << "Character in current room: ";
      std::cout << u->getLocation()->getCharacter() << "\n";
      break;
    }
    case ITEMS:
    {
      std::cout << "Current items in room is: \n";
      for (auto i : u->getLocation()->getItems()) {
        std::cout << i->getName() << "\n";
      }
      break;
    }
    case LOCATIONS:
    {
      std::cout << "Current available locations are: \n";
      for (auto it : l->getAllLocs()) {
        if (it.second->isUnlocked() && it.second != u->getLocation())
          std::cout << it.second->getName() << "\n";
      }
      break;
    }
    case INVENTORY: {
      std::cout << "Current inventory is: \n";
      for (auto i : u->getInventory()) {
        std::cout << i->getName() << "\n";
      }
      break;
    }
    case DIRECTIONS: {
      std::cout << "TO PLAY: Francis can \'GO\' to locations, \'PICKUP\' to "
      "pickup items in the world, \'USE\' to use an item on a character or "
      "world item, \'TALK\' to talk to the characters in the world. Type "
      "\'HELP\' to get info about the game.\n";
      break;
    }
    default:
      std::cout << "Not a valid input.\n";
    }
  }
