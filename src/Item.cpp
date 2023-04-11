#include"Item.h"
#include<string>
#include"Location.h"
#include"Player.h"
#include"LocationList.h"
#include<iostream>

std::string Item::getName() {
  return name;
}

bool Usable::useOn(std::string, Player*) {
  return false;
}

bool Usable::useOn(Item*, Player*) {
  return false;
}

bool Bone::useOn(std::string c, Player* p) {
  if (c.compare("FINN") == 0
  && p->getLocation()->getName().compare("Gallery") == 0) {
    std::cout << "Woof! (Well, thank you feller! mighty appreciated!)\n";
    std::cout << "A small key drops to the ground. The tag says "
    "\"Key to back room\"\n";
    p->getLocation()->addItem(new Key1());
    return true;
  }
  return false;
}

bool Key1::useOn(Item* i, Player* p) {
  if (i->getName().compare("DOOR") == 0
    && p->getLocation()->getName().compare("Gallery") == 0) {
      std::cout << "The back room has been unlocked." << std::endl;
      p->getGameLocs()->getLocation("BACK ROOM")->unlock();
      p->getGameLocs()->getLocation("GALLERY")->removeItem(i);
      return true;
    } else {
      return false;
  }
}

bool Magnet::useOn(Item* i, Player* p) {
  if (i->getName().compare("GRATE") == 0 && p->getLocation()->getName()
  .compare("Back Room") == 0) {
    std::cout << "You hover the magnet above the grate and... *ting!* a coin "
    "sticks to the magnet! (You throw the magnet away)\n";
    std::cout << "\"Oh... Does it need some cleaning in there? U-Uh I mean "
    "youre the boss... please don't fire me.\"\n";
    p->addItem(new Coin());
    return true;
  }
  return false;
}

bool Coin::useOn(std::string i, Player* p) {
  if (i.compare("GUARD") == 0 && p->getLocation()->getName()
  .compare("Entryway") == 0) {
    std::cout << "You throw the coin at the guard and it hits him in the "
    "eye. He didn't seem to like that. He immediately throws you out the "
    "door." << std::endl;
    p->setState(1);
    return true;
    }
  return false;
}

bool Coin::useOn(Item* i, Player* p) {
  if (i->getName().compare("VENDING MACHINE") == 0 &&
    p->getLocation()->getName().compare("Entryway") == 0) {
      std::cout << "You insert the coin and can of pop falls out into the open"
      " slot.\n";
      p->getLocation()->addItem(new Pop());
      return true;
    }
  return false;
}

bool Pop::useOn(Item* i, Player* p) {
  if (i->getName().compare("LAXATIVES") == 0 && p->getLocation()->getName()
  .compare("Security Room") == 0) {
    std::cout << "You take the cap off of the pop bottle and dump in an "
    "unhealthy amount of laxative. You gently shake the pop to mix it and "
    "add the laxative pop to your bag." << std::endl;
    p->addItem(new LaxativePop());
    return true;
  }
  return false;
}

bool LaxativePop::useOn(std::string i, Player* p) {
  if (i.compare("GUARD") == 0 && p->getLocation()->getName()
  .compare("Entryway") == 0) {
    std::cout << "As the guard looks away you sneakily replace his current "
    "drink with your laxative pop. You inconspicuously whistle and lean "
    "against the wall until the guard has finished his pop and promptly starts"
    " running for the bathroom." << std::endl;
    std::cout << "There are no longer any more pairs of eyes watching you "
    "here." << std::endl;
    p->getLocation()->setCharacter("");
    return true;
  }
  return false;
}

bool ToiletPaper::useOn(std::string i, Player* p) {
  if (i.compare("TOILET MAN") == 0 && p->getLocation()->getName()
    .compare("Bathroom") == 0) {
      std::cout << "Oh you are a lifesaver! Here have... umm... this plunger? "
      "Listen I don't have much to give you, if you don't want it just leave\n";
      p->addItem(new Plunger());
      return true;
    }
  return false;
}

bool Plunger::useOn(std::string i, Player* p) {
  if (i.compare("CHLOE") == 0
      && p->getLocation()->getName().compare("Back Room") == 0) {
        std::cout << "Thanks! That was a big help! Wh-what? You are asking for"
        " an item in return? Gee, uh I have this screwdriver? Does that help?"
        << std::endl;
        p->addItem(new Screwdriver());
        return true;
      }
  return false;
}

bool Keycard::useOn(Item* i, Player* p) {
  if (i->getName().compare("CARD READER") == 0 && p->getLocation()->getName()
  .compare("Entryway") == 0) {
    if (p->getLocation()->getCharacter().compare("") == 0) {
      std::cout << "You slide the bar across the scanner. It beeps. You may "
      "now enter the admin office." << std::endl;
      p->getGameLocs()->getLocation("ADMIN OFFICE")->unlock();
    } else {
      std::cout << "Hey! What are you doing over there? You don't work here!"
      "\nThe guard rushes over to you and holds you by your shirt."
      "\nI'm going to have to call the cops so we can look into this "
      "suspiscious behaviour." << std::endl;
      p->setState(1);
    }
    return true;
  }
  return false;
}

bool Hammer::useOn(Item* i, Player* p) {
  if (i->getName().compare("MIRROR") == 0 && p->getLocation()->getName()
  .compare("Bathroom") == 0) {
    std::cout << "You seemed to have knocked a fragment off of the mirror. "
    "Hopefully nobody heard that." << std::endl;
    p->getLocation()->addItem(new MirrorFragment());
    return true;
  }
  return false;
}

bool MirrorFragment::useOn(Item* i, Player* p) {
  if (i->getName().compare("LASERS") == 0 && p->getLocation()->getName()
  .compare("Corridor") == 0) {
    std::cout << "You use the mirror to reflect the lasers back to the device. "
    "That seems to have fried the system. Now you can get to "
    "that secret room!" << std::endl;
    p->getGameLocs()->getLocation("SECRET ROOM")->unlock();
    return true;
  }
  return false;
}

bool Hairspray::useOn(Item* i, Player* p) {
  if (i->getName().compare("BLINKING DEVICE") == 0
    && p->getLocation()->getName().compare("Corridor") == 0) {
    std::cout << "You carefully spray the hairspray around the blinking device"
    ". As mist fills the air you see lasers emerge. If you were to walk "
    "through it would set off the alarm." << std::endl;
    p->getLocation()->removeItem(i);
    p->getLocation()->addItem(new Item("LASERS"));
    return true;
  }
  return false;
}

bool Screwdriver::useOn(Item* i, Player* p) {
  if (i->getName().compare("VENT") == 0
    && p->getLocation()->getName().compare("Outside") == 0) {
      std::cout << "You unscrew the screws on the vent, you see a faint light "
      "at the end of the vent.\n";
      p->getGameLocs()->getLocation("VENT")->unlock();
      p->getGameLocs()->getLocation("SECURITY ROOM")->unlock();
      p->getLocation()->removeItem(i);
      return true;
    }
  return false;
  }

bool AccessCodes::useOn(Item* i, Player* p) {
  if (i->getName().compare("SECURITY CONSOLE") == 0
    && p->getLocation()->getName().compare("Security Room") == 0) {
    std::cout << "You input the security codes and the cameras in the showcase "
    "turn off!\n";
    p->getGameLocs()->getLocation("SHOWCASE")->
      removeItem(p->getGameLocs()
        ->getLocation("SHOWCASE")->findItem("CAMERAS"));
    return true;
  }
  return false;
}

bool Knife::useOn(std::string i, Player* p) {
  if (i.compare("GUARD") == 0 && p->getLocation()->getName()
  .compare("Entryway") == 0) {
    std::cout << "You rush the guard with the knife. He watches you run "
    "towards him and calmly pulls out a taser. Zap!" << std::endl;
    p->setState(1);
    return true;
    }
  return false;
}

bool Knife::useOn(Item* i, Player* p) {
  if (i->getName().compare("FAKE PAINTING") == 0 && p->getLocation()->getName()
  .compare("Showcase") == 0) {
    if (p->getLocation()->findItem("CAMERAS") != nullptr) {
        std::cout << "You go to slash the fake painting and sirens start"
        " blaring. Police swarm in and arrest you.\n";
        p->setState(1);
      } else {
        std::cout << "You slice around the border of the fake painting. It "
        "reveals a long corridor leading to an elegant looking door.\n";
        p->getGameLocs()->getLocation("CORRIDOR")->unlock();
      }
    return true;
  }
return false;
}

bool IceCream::useOn(std::string i, Player* p) {
  if (i.compare("MASKED MAN") == 0
    && p->getLocation()->getName().compare("Outside") == 0) {
      std::cout << "Thanks friend. Here a little something I was gonna use "
      "today for... something...but I'm not in the mood anymore. You can have "
      "it, think of it as a...souvenir. We'll be in touch.\n";
      std::cout << "The masked man hands you a card with the face of a woman."
      " It appears to be of the owner of the gallery Natalia Von Schmidt.\n";
      p->addItem(new Keycard());
      return true;
    }
  return false;
}
