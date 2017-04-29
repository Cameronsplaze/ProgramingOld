#include "Armor.h"

Armor::Armor():Item()
{
    armorType_ = Category::LIGHT;
    armorClass_ = 0;
}

Armor::Armor(int cost, int id, int weight, std::string name, std::string description, std::string category, int armorClass):Item(cost, id, weight, name, description,Item::ItemType::ARMOR)
{
    setCategory(category);
    armorClass_ = armorClass;
}

std::string Armor::getCategory()
{
    if (armorType_ == Category::LIGHT)
    {
        return "LIGHT";
    }
    else if (armorType_ == Category::MEDIUM)
    {
        return "MEDIUM";
    }
    else if (armorType_ == Category::HEAVY)
    {
        return "HEAVY";
    }
}

int Armor::getArmorClass()
{
    return armorClass_;
}

void Armor::setCategory(Category type)
{
    armorType_ = type;
}

void Armor::setCategory(std::string s)
{
    if (s == "LIGHT")
    {
        armorType_ = Category::LIGHT;
    }
    else if (s == "MEDIUM")
    {
        armorType_ = Category::MEDIUM;
    }
    else if (s == "HEAVY")
    {
        armorType_ = Category::HEAVY;
    }
    else if (s == "SHIELD")
    {
        armorType_ = Category::SHIELD;
    }
}

void Armor::setArmorClass(int armorClass)
{
    armorClass_ = armorClass;
}
