#ifndef ARMOR_H_INCLUDED
#define ARMOR_H_INCLUDED

#include "Item.h"

class Armor : public Item
{
public:
    enum Category{LIGHT,MEDIUM,HEAVY,SHIELD};
    Armor();
    Armor(int cost, int id, int weight, std::string name, std::string description, std::string category, int armorClass);
    std::string getCategory();
    int getArmorClass();
    void setCategory(Category type);
    void setCategory(std::string s);
    void setArmorClass(int armorClass);
private:
    Category armorType_;
    int armorClass_;
};

#endif // ARMOR_H_INCLUDED
