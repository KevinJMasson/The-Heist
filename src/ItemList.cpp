#include"ItemList.h"
#include<string>
#include<map>
#include<utility>

ItemList::ItemList() {
  Bone* b = new Bone();
  items.insert(std::pair<std::string, Usable*> ("BONE", b));
  Key1* k1 = new Key1();
  items.insert(std::pair<std::string, Usable*> ("KEY", k1));
  Plunger* p = new Plunger();
  items.insert(std::pair<std::string, Usable*> ("PLUNGER", p));
  ToiletPaper* tp = new ToiletPaper();
  items.insert(std::pair<std::string, Usable*> ("TOILET PAPER", tp));
  Magnet* m = new Magnet();
  items.insert(std::pair<std::string, Usable*> ("MAGNET", m));
  Coin* c = new Coin();
  items.insert(std::pair<std::string, Usable*> ("COIN", c));
  Pop* po = new Pop();
  items.insert(std::pair<std::string, Usable*> ("POP", po));
  Hammer* hm = new Hammer();
  items.insert(std::pair<std::string, Usable*> ("HAMMER", hm));
  MirrorFragment* mf = new MirrorFragment();
  items.insert(std::pair<std::string, Usable*> ("MIRROR FRAGMENT", mf));
  Keycard* kc = new Keycard();
  items.insert(std::pair<std::string, Usable*> ("KEYCARD", kc));
  Hairspray* hs = new Hairspray();
  items.insert(std::pair<std::string, Usable*> ("HAIRSPRAY", hs));
  LaxativePop* lp = new LaxativePop();
  items.insert(std::pair<std::string, Usable*> ("LAXATIVE POP", lp));
  Screwdriver* sd = new Screwdriver();
  items.insert(std::pair<std::string, Usable*> ("SCREWDRIVER", sd));
  AccessCodes* ac = new AccessCodes();
  items.insert(std::pair<std::string, Usable*> ("ACCESS CODES", ac));
  Knife* k = new Knife();
  items.insert(std::pair<std::string, Usable*> ("KNIFE", k));
  Usable* pa = new Usable("PAINTING");
  items.insert(std::pair<std::string, Usable*> ("PAINTING", pa));
  IceCream* ic = new IceCream;
  items.insert(std::pair<std::string, Usable*> ("ICE CREAM", ic));
}

ItemList::~ItemList() {
  for (std::map<std::string, Usable*>::iterator it = items.begin();
    it != items.end(); ++it) {
      delete it->second;
    }
}

Usable* ItemList::getItem(std::string s) {
  std::map<std::string, Usable*>::iterator it = items.find(s);

  if (it != items.end())
    return it->second;
  else
    return nullptr;
}
