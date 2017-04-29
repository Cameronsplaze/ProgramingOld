#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include "Entity.hpp"
#include "Dice.h"
#include <iostream>

class Item : public Entity
{
public:
	virtual void use()
	{}

    enum ItemType{WEAPON,ARMOR,MISC};
    Item();
    Item(int cost, int id, int weight, std::string name, std::string description);
	Item(int cost, int id, int weight, std::string name, std::string description, Item::ItemType type);
    // Accessors Functions
    int getCost();
    int getId();
    int getWeight();
    std::string getName();
    std::string getDescription();
    sf::Sprite getSprite();
    Item::ItemType getType();
    sf::Texture & getTexture();
    // Mutator Functions
    void setCost(int cost);
    void setId(int id);
    void setWeight(int weight);
    void setName(std::string name);
    void setDescription(std::string description);
    void setSprite(sf::Texture &sprite);
    void setType(Item::ItemType type);
    void setTexture(sf::Texture &tex);
    // Weapon accessors
	virtual bool isHeavy();
	virtual bool isMartial();
	virtual int range();
	virtual Dice damage();
	// Armor accessors
    virtual std::string getCategory();
    virtual int getArmorClass();
protected:
    int cost_;
    int ID_;
    int weight_;
    std::string name_;
    std::string description_;
    Item::ItemType type_;
    sf::Texture tex_;
};

#endif // ITEM_H_INCLUDED
