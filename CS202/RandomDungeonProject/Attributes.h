#ifndef ATTRIBUTES_H_INCLUDED
#define ATTRIBUTES_H_INCLUDED
#include <iostream>
#include <map>

class Attributes
{
public:
    Attributes();
    Attributes(int strength, int dexterity, int intellect, int wisdom, int constitution);
    // takes "STR","DEX","INT","WIS", or "CON" as argument and returns the corresponding value
    int getAttribute(std::string atr);
    // takes "STR","DEX","INT","WIS", or "CON" as argument and sets it to value
    void setAttribute(std::string atr, int value);
private:
    // map of "STR","DEX","INT","WIS","CON" that hold int values for the stats
    std::map<std::string,int> attributes_;
};

#endif // ATTRIBUTES_H_INCLUDED
