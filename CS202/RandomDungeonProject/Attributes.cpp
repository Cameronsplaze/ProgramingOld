#include "Attributes.h"

Attributes::Attributes()
{
    attributes_["STR"] = 0;
    attributes_["DEX"] = 0;
    attributes_["INT"] = 0;
    attributes_["WIS"] = 0;
    attributes_["CON"] = 0;
}

Attributes::Attributes(int strength, int dexterity, int intellect, int wisdom, int constitution)
{
    attributes_["STR"] = strength;
    attributes_["DEX"] = dexterity;
    attributes_["INT"] = intellect;
    attributes_["WIS"] = wisdom;
    attributes_["CON"] = constitution;
}

int Attributes::getAttribute(std::string atr)
{
    return attributes_[atr];
}

void Attributes::setAttribute(std::string atr, int value)
{
    attributes_[atr] = value;
}
