#include"LocationList.h"
#include"Location.h"
#include<utility>
#include"Item.h"
#include<vector>
#include<string>
#include<map>

LocationList::LocationList() {
  Location* l = new Location(true, "Gallery", "FINN");
  l->addItem(new Bone());
  l->addItem(new Item("DOOR"));
  locations.insert(std::pair<std::string, Location*> ("GALLERY", l));

  Location* l2 = new Location(false, "Back Room", "CHLOE");
  l2->addItem(new ToiletPaper());
  l2->addItem(new Item("GRATE"));
  locations.insert(std::pair<std::string, Location*> ("BACK ROOM", l2));

  Location* l3 = new Location(false, "Security Room", "");
  l3->addItem(new Item("LAXATIVES"));
  l3->addItem(new Knife());
  l3->addItem(new Item("SECURITY CONSOLE"));
  l3->addItem(new IceCream);
  locations.insert(std::pair<std::string, Location*> ("SECURITY ROOM", l3));

  Location* l4 = new Location(true, "Outside", "MASKED MAN");
  l4->addItem(new Item("VENT"));
  l4->addItem(new Hammer());
  locations.insert(std::pair<std::string, Location*> ("OUTSIDE", l4));

  Location* l5 = new Location(true, "Bathroom", "TOILET MAN");
  l5->addItem(new Item("MIRROR"));
  locations.insert(std::pair<std::string, Location*> ("BATHROOM", l5));

  Location* l6 = new Location(false, "Vent", "");
  l6->addItem(new Magnet());
  locations.insert(std::pair<std::string, Location*> ("VENT", l6));

  Location* l7 = new Location(false, "Admin Office", "NATALIA");
  l7->addItem(new Hairspray());
  l7->addItem(new AccessCodes());
  locations.insert(std::pair<std::string, Location*> ("ADMIN OFFICE", l7));

  Location* l8 = new Location(true, "Showcase", "");
  l8->addItem(new Item("FAKE PAINTING"));
  l8->addItem(new Item("CAMERAS"));
  locations.insert(std::pair<std::string, Location*> ("SHOWCASE", l8));

  Location* l9 = new Location(false, "Secret Room", "");
  l9->addItem(new Item("PAINTING"));
  locations.insert(std::pair<std::string, Location*> ("SECRET ROOM", l9));

  Location* l10 = new Location(false, "Corridor", "");
  l10->addItem(new Item("BLINKING DEVICE"));
  locations.insert(std::pair<std::string, Location*> ("CORRIDOR", l10));

  Location* l11 = new Location(true, "Entryway", "GUARD");
  l11->addItem(new Item("VENDING MACHINE"));
  l11->addItem(new Item("CARD READER"));
  locations.insert(std::pair<std::string, Location*> ("ENTRYWAY", l11));
}

LocationList::~LocationList() {
  for (std::map<std::string, Location*>::iterator it = locations.begin();
    it != locations.end(); ++it) {
      delete it->second;
    }
}

Location* LocationList::getLocation(std::string s) {
  std::map<std::string, Location*>::iterator it = locations.find(s);
  if (it != locations.end())
    return it->second;
  else
    return nullptr;
}

std::map<std::string, Location*> LocationList::getAllLocs() {
  return locations;
}
