#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <vector>
#include <sstream>
#include "Item.h"

class Inventory
{
public:
	// constructor
	Inventory();
	// destructor to delete item memory
	~Inventory();
    // adds itm to items_
    void add(Item *itm);
    // add vector<Item>
    void addItems(std::vector<Item*> itms);
    // returns items_
    std::vector<Item*> & getItems();
    // returns the item with string name
    Item* get(std::string name);
    // returns the items_[index]
    Item* get(int index);
    // returns the item with id_ id
    Item* getById(int id);
    // removes item with string name from the vector
    void removeItem(std::string name);
    // removes items_[index] from the vector
    void removeItem(int index);
    // removes item with id_ id from the vector
    void removeById(int id);
    // returns size of items_
    int size();
    // draws the inventory
    void draw(sf::RenderWindow &window,sf::Vector2f pos);

private:
	// vector of items
	std::vector<Item*> items_;

	// Functions and variables for drawing inventory
    // updates the inventory window
    void update(sf::RenderWindow &window);
    // processes any input
    bool processInput(sf::RenderWindow &window);
    // creates a description based on item type
    sf::String getDescription(Item *itm);
    // font for drawing
    sf::Font AlbertText_;
    // border for the inventory window
    sf::RectangleShape border_;
    // border for the image box
    sf::RectangleShape imageBox_;
    // border for the list of items
    sf::RectangleShape itemList_;
    // border for the description + stats box
    sf::RectangleShape descBox_;
    // box to surround selected item
    sf::RectangleShape selectionBox_;
    // index for selected item
    int selectedItem_;
};

#endif // INVENTORY_H_INCLUDED
