#ifndef ITEMMANAGER_H_INCLUDED
#define ITEMMANAGER_H_INCLUDED

#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Dice.h"
#include <vector>
#include <fstream>

class ItemManager
{
public:
    ItemManager();
    ~ItemManager();
    std::vector<Item*> getItems();
private:
    Weapon * makeWeapon(std::ifstream &ifs);
    Armor * makeArmor(std::ifstream &ifs);
    std::vector<Item*> itemList_;
};


#endif // ITEMMANAGER_H_INCLUDED
