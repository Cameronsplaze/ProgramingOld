#include "Inventory.h"

// Constructor
Inventory::Inventory()
{

}
// Destructor to delete Item memory
Inventory::~Inventory()
{
	for (int i = 0; i < items_.size(); ++i)
	{
		delete items_[i];
	}
}
// adds itm to items_
void Inventory::add(Item *itm)
{
    items_.push_back(itm);
}
// add vector<Item>
void Inventory::addItems(std::vector<Item*> itms)
{
    for (int i=0; i<itms.size(); ++i)
    {
        items_.push_back(itms[i]);
    }
}
// returns items_
std::vector<Item*> & Inventory::getItems()
{
    return items_;
}
// returns the item with string name
Item * Inventory::get(std::string name)
{
    for (int i=0; i<items_.size(); ++i)
    {
        if (items_[i]->getName() == name)
        {
            return items_[i];
        }
    }
	Item* nullitm = 0;
	return nullitm;
}
// returns the items_[index]
Item * Inventory::get(int index)
{
	return items_[index];
}
// returns the item with id_ id
Item * Inventory::getById(int id)
{
    for (int i=0; i<items_.size(); ++i)
    {
        if (items_[i]->getId() == id)
        {
            return items_[i];
        }
    }
	Item *nullitm = 0;
	return nullitm;
}
// removes item with string name from the vector
void Inventory::removeItem(std::string name)
{
    for (int i=0; i<items_.size(); ++i)
    {
        if (items_[i]->getName() == name)
        {
			delete items_[i];
            items_.erase(items_.begin()+i);
        }
    }
}
// removes items_[index] from the vector
void Inventory::removeItem(int index)
{
	delete items_[index];
    items_.erase(items_.begin()+index);
}
// removes item with id_ id from the vector
void Inventory::removeById(int id)
{
    for (int i=0; i<items_.size(); ++i)
    {
        if (items_[i]->getId() == id)
        {
			delete items_[i];
            items_.erase(items_.begin()+i);
        }
    }
}
// returns size of items_
int Inventory::size()
{
    return items_.size();
}
// draws the Inventory
void Inventory::draw(sf::RenderWindow &window, sf::Vector2f pos)
{
    window.clear(sf::Color(50, 50, 50));
    // set selected item to be first item
    selectedItem_ = 0;
    // set the border_ around pos
    border_.setSize(sf::Vector2f(220, 240));
    border_.setOutlineColor(sf::Color::Black);
    border_.setOutlineThickness(5);
    border_.setPosition(pos.x-110,pos.y-120);
    // set the imageBox_ border_
    imageBox_.setSize(sf::Vector2f(110, 120));
    imageBox_.setOutlineColor(sf::Color::Black);
    imageBox_.setOutlineThickness(1);
    imageBox_.setPosition(pos.x-110,pos.y-120);
    // set the itemList_ border_
    itemList_.setSize(sf::Vector2f(110, 120));
    itemList_.setOutlineColor(sf::Color::Black);
    itemList_.setOutlineThickness(1);
    itemList_.setPosition(pos.x-110,pos.y);
    // set the description box
    descBox_.setSize(sf::Vector2f(110, 240));
    descBox_.setOutlineColor(sf::Color::Black);
    descBox_.setOutlineThickness(1);
    descBox_.setPosition(pos.x,pos.y-120);
    // set the selection box
    selectionBox_.setSize(sf::Vector2f(107, 15));
    selectionBox_.setOutlineColor(sf::Color::Yellow);
    selectionBox_.setOutlineThickness(1);
    selectionBox_.setPosition(pos.x-110,pos.y);
    // color of the window
    sf::Color grey(70,70,70,255);
    border_.setFillColor(grey);
    // color for imageBox_
    imageBox_.setFillColor(sf::Color::White);
    // color for itemList_
    sf::Color lighterGrey(200,200,200,255);
    itemList_.setFillColor(lighterGrey);
    // color for descBox_
    sf::Color lightestGrey(220,220,220,255);
    descBox_.setFillColor(lightestGrey);
    // load font Albert Text
    if (!AlbertText_.loadFromFile("media/AlbertText.ttf"))
    {
        std::cout << "Error!" << std::endl;
    }
    while(processInput(window) == true)
    {
        update(window);
    }
}
// updates the inventory window
void Inventory::update(sf::RenderWindow &window)
{
    window.clear(sf::Color(50, 50, 50));
    // set the image
    imageBox_.setTexture(items_[selectedItem_]->getSprite().getTexture());
    // draw the border_
    window.draw(border_);
    window.draw(imageBox_);
    window.draw(itemList_);
    window.draw(descBox_);
    // selection box around selected item
    selectionBox_.setPosition(itemList_.getPosition().x+1,itemList_.getPosition().y+1+16*selectedItem_);
    window.draw(selectionBox_);
    // array of item names to draw to itemList_ box
	sf::Text *itemNames = new sf::Text[items_.size()];
    for (int i=0; i<items_.size(); ++i)
    {
        itemNames[i].setFont(AlbertText_);
        itemNames[i].setCharacterSize(12);
        itemNames[i].setColor(sf::Color::Black);
        itemNames[i].setPosition(itemList_.getPosition().x+5,itemList_.getPosition().y+1+16*i);
        itemNames[i].setString(items_[i]->getName());
        for (int k=0; k<itemNames[i].getString().getSize(); ++k)
        {
            float scale = 1;
            while (itemNames[i].findCharacterPos(k).x > descBox_.getPosition().x-5)
            {
                scale -= 0.05;
                itemNames[i].scale(scale,1);
                itemNames[i].setPosition(itemList_.getPosition().x+5,itemList_.getPosition().y+1+16*i);
            }
        }
        window.draw(itemNames[i]);
    }
	delete[] itemNames;
    // sf::Text of item description to draw to the description box
    sf::Text itemDescs;
    // create the description to be written
    sf::String description = getDescription(items_[selectedItem_]);
    // set descriptions font,size,color, and position
    itemDescs.setFont(AlbertText_);
    itemDescs.setCharacterSize(12);
    itemDescs.setColor(sf::Color::Black);
    itemDescs.setPosition(descBox_.getPosition().x+5,descBox_.getPosition().y+5);
    itemDescs.setString(description);
    sf::String tempDesc = itemDescs.getString();
    for (int i=0; i<itemDescs.getString().getSize(); ++i)
    {
        if (itemDescs.getString()[i] == ' ')
        {
            for (int k=i+1; k<itemDescs.getString().getSize(); ++k)
            {
                if (itemDescs.findCharacterPos(k).x > descBox_.getPosition().x+110)
                {
                    description.insert(i+1,"\n");
                    itemDescs.setString(description);
                    break;
                }
                else if (itemDescs.getString()[k] == ' ')
                {
                    break;
                }
            }
        }
    }
    window.draw(itemDescs);
    // display the window
    window.display();
}
// processes any input
bool Inventory::processInput(sf::RenderWindow &window)
{
    //Reads window events
	sf::Event event;
	while (window.pollEvent(event))
	{
        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::I)
            {
                return false;
            }
            else if (event.key.code == sf::Keyboard::Up)
            {
                if (selectedItem_ > 0)
                {
                    selectedItem_--;
                }
                else
                {
                    selectedItem_ = items_.size()-1;
                }
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                if (selectedItem_ < items_.size()-1)
                {
                    selectedItem_++;
                }
                else
                {
                    selectedItem_ = 0;
                }
            }
        }
	}
	return true;
}
// returns a description for the selected item
sf::String Inventory::getDescription(Item *itm)
{
    // string stream to convert int to string
    std::stringstream ss;
    // Prints the description
    sf::String temp = "Description:\n";
    temp += items_[selectedItem_]->getDescription();
    temp += "\n";
    // Prints the cost
    ss << itm->getCost() << "\n";
    temp += "Cost: ";
    temp += ss.str();
    ss.str("");
    // Prints the weight
    ss << itm->getWeight() << "\n";
    temp += "Weight: ";
    temp += ss.str();
    ss.str("");
    if (itm->getType() == Item::WEAPON)
    {
        // Prints martial
        if (itm->isMartial())
        {
            temp += "Martial: Yes\n";
        }
        else
        {
            temp += "Martial: No\n";
        }
        // Prints heavy
        if (itm->isHeavy())
        {
            temp += "Heavy: Yes\n";
        }
        else
        {
            temp += "Heavy: No\n";
        }
        // Prints the range
        ss << itm->range() << "\n";
        temp += "Range: ";
        temp += ss.str();
        ss.str("");
        // Prints the damage
        ss << itm->damage().getDieType() << "d" << itm->damage().getDieRoll() << "\n";
        temp += "Damage: ";
        temp += ss.str();
        ss.str("");
    }
    else if (itm->getType() == Item::ARMOR)
    {
        // Prints the armor type
        temp += "Armor Type: ";
        temp += itm->getCategory();
        temp += "\n";
        // Prints the armor class
        ss << itm->getArmorClass() << "\n";
        temp += "Armor Class: ";
        temp += ss.str();
        ss.str("");
    }
    return temp;
}
















