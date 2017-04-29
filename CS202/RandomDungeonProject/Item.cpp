#include "Item.h"

Item::Item():Entity()
{
    // Initially set all variables to null practically
    cost_ = -1;
    ID_ = -1;
    weight_ = -1;
    name_ = "NULL";
    description_ = "NULL";
    // sets type to misc by default
    type_ = Item::ItemType::MISC;
}

Item::Item(int cost, int id, int weight, std::string name, std::string description):Entity()
{
    cost_ = cost;
    ID_ = id;
    weight_ = weight;
    name_ = name;
    description_ = description;
    // sets type to misc by default
    type_ = Item::ItemType::MISC;
}

Item::Item(int cost, int id, int weight, std::string name, std::string description, Item::ItemType type):Entity()
{
	cost_ = cost;
	ID_ = id;
	weight_ = weight;
	name_ = name;
	description_ = description;
	type_ = type;
}

int Item::getCost()
{
    return cost_;
}

int Item::getId()
{
    return ID_;
}

int Item::getWeight()
{
    return weight_;
}

std::string Item::getName()
{
    return name_;
}

std::string Item::getDescription()
{
    return description_;
}

sf::Sprite Item::getSprite()
{
    return sprite_;
}

Item::ItemType Item::getType()
{
	return type_;
}

sf::Texture & Item::getTexture()
{
    return tex_;
}

void Item::setCost(int cost)
{
    cost_ = cost;
}

void Item::setId(int id)
{
    ID_ = id;
}

void Item::setWeight(int weight)
{
    weight_ = weight;
}

void Item::setName(std::string name)
{
    name_ = name;
}

void Item::setDescription(std::string description)
{
    description_ = description;
}

void Item::setSprite(sf::Texture &sprite)
{
    sprite_.setTexture(sprite);
}

void Item::setType(Item::ItemType type)
{
	type_ = type;
}

void Item::setTexture(sf::Texture &tex)
{
    tex_ = tex;
}

// Weapon accessors
bool Item::isHeavy()
{
    return false;
}
bool Item::isMartial()
{
    return false;
}
int Item::range()
{
    return 0;
}
Dice Item::damage()
{
    Dice damage;
    return damage;
}
// Armor accessors
std::string Item::getCategory()
{
    return "NULL";
}
int Item::getArmorClass()
{
    return 0;
}

