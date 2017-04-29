#pragma once

#include <string>

#include "Event.hpp"

Event::Event()
{}

Event::Event(eventType type, sf::FloatRect& rect)
{
	add(type, rect);
}

void Event::add(eventType type, sf::FloatRect rect, bool state)
{
	states_[type] = state;
	rects_[type] = rect;
}

void Event::add(sf::Vector2i pos, bool state)
{
	states_[ATTACK] = state;
	location_ = pos;
}


void Event::setLocation(sf::Vector2i pos)
{
	location_ = pos;
}
sf::Vector2i Event::getLocation()
{
	return location_;
}
void Event::setRect(eventType type, sf::FloatRect rect)
{
	rects_[type] = rect;
}

bool Event::getState(eventType type)
{
	return states_[type];
}

void Event::setState(eventType type, bool state)
{
	states_[type] = state;
}

sf::FloatRect Event::getRect(eventType type)
{
	return rects_[type];
}

bool Event::getCollisionState()
{
	return states_[COLLISION];
}


void Event::setCollisionState(bool state)
{
	states_[COLLISION] = state;
}


void Event::setCollisionRect(sf::FloatRect rect)
{
	rects_[COLLISION] = rect;
}
