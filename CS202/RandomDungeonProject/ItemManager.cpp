#include "ItemManager.h"

ItemManager::ItemManager()
{
    std::ifstream ifs("media/ITEM_LIST.txt");
    std::string input;
    while (getline(ifs,input))
    {
        if (input == "WEAPON")
        {
            Weapon *temp = makeWeapon(ifs);
            itemList_.push_back(temp);
        }
        else if (input == "ARMOR")
        {
            Armor *temp = makeArmor(ifs);
            itemList_.push_back(temp);
        }
    }
    ifs.close();
}

Weapon * ItemManager::makeWeapon(std::ifstream &ifs)
{
    std::string input,name,desc;
    int cost,id,weight,range;
    bool heavy,martial;
    Dice damage;
    sf::Texture tex;

    for (int i=0; i<10; ++i)
    {
        getline(ifs,input);
        switch (i)
        {
        case 0:
            id = atoi(input.c_str());
            break;
        case 1:
            name = input;
            break;
        case 2:
            desc = input;
            break;
        case 3:
            {
                const std::string spriteFile = input;
                if (!tex.loadFromFile(spriteFile))
                {
                    std::cout << "Error loading file: " << spriteFile << std::endl;
                }
            }
            break;
        case 4:
            cost = atoi(input.c_str());
            break;
        case 5:
            weight = atoi(input.c_str());
            break;
        case 6:
            heavy = atoi(input.c_str());
            break;
        case 7:
            martial = atoi(input.c_str());
            break;
        case 8:
            range = atoi(input.c_str());
            break;
        case 9:
            {
                std::string temp = "";
                int dieType = input.at(0) - '0';
                for (int a=2; a<input.length(); ++a)
                {
                    temp += input.at(a);
                }
                int dieRolls;
                dieRolls = atoi(temp.c_str());
                damage.setRolls(dieRolls);
                damage.setType(dieType);
            }
            break;
        }
    }
    Weapon *temp = new Weapon(cost,id,weight,name,desc,heavy,martial,range,damage);
    temp->setTexture(tex);
    temp->setSprite(temp->getTexture());
    return temp;
}

Armor * ItemManager::makeArmor(std::ifstream &ifs)
{
    std::string input,name,desc,armorType;
    int cost,id,weight,armorClass;
    sf::Texture tex;

    for (int i=0; i<8; ++i)
    {
        getline(ifs,input);
        switch (i)
        {
        case 0:
            id = atoi(input.c_str());
            break;
        case 1:
            name = input;
            break;
        case 2:
            desc = input;
            break;
        case 3:
            {
                const std::string spriteFile = input;
                if (!tex.loadFromFile(spriteFile))
                {
                    std::cout << "Error loading file: " << spriteFile << std::endl;
                }
            }
            break;
        case 4:
            cost = atoi(input.c_str());
            break;
        case 5:
            weight = atoi(input.c_str());
            break;
        case 6:
            armorType = input;
            break;
        case 7:
            armorClass = atoi(input.c_str());
            break;
        }
    }
    Armor *temp = new Armor(cost,id,weight,name,desc,armorType,armorClass);
    temp->setTexture(tex);
    temp->setSprite(temp->getTexture());
    return temp;
}

ItemManager::~ItemManager()
{
    /*for (int i=0; i<itemList_.size(); ++i)
    {
        if (itemList_[i] != 0)
        {
            delete itemList_[i];
            std::cout << "here";
        }
    }*/
}

std::vector<Item*> ItemManager::getItems()
{
    return itemList_;
}
