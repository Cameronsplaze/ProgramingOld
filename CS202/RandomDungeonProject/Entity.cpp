
#include <list>

#include "Entity.hpp"

#include <iostream>

Entity::Entity() : solid_(true), visible_(true), canUse_(false), facing(SOUTH)
{
}


void Entity::setID(std::size_t id)
{
	id_ = id;
}
std::size_t Entity::getID()
{
	return id_;
}
void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = sprite_.getTexture();

	// draw the vertex array
	target.draw(sprite_, states);
}


void Entity::draw(sf::RenderWindow wind)
{
	wind.draw(sprite_);
}

bool Entity::canUse()
{
	return canUse_;
}
bool Entity::isSolid()
{
	return solid_;
}

sf::Vector2i Entity::getMyRoom()
{
	return myRoom_;
}
void Entity::setMyRoom(sf::Vector2i pos)
{
	myRoom_ = pos;
}

sf::FloatRect Entity::getBoundingBox()
{
	return sprite_.getGlobalBounds();
}
