/*
Alex Medeiros
Event Class
	Hold information about collisions for passing it between 
	player and engine.
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <map>

enum eventType { COLLISION, USEOBJECT, ATTACK };

class Event
{
public:
	Event();
	Event(eventType str, sf::FloatRect& rect);

	//void add(std::string& str);
	void add(eventType type, sf::FloatRect rect, bool state = false); 
	void Event::add(sf::Vector2i pos, bool state);

	void setState(eventType type, bool state);
	void setRect(eventType type, sf::FloatRect rect);

	sf::FloatRect getRect(eventType type);
	bool getState(eventType type);

	bool getCollisionState();
	sf::Vector2i getLocation();

	void setCollisionState(bool state);
	void setCollisionRect(sf::FloatRect rect);
	void setLocation(sf::Vector2i pos);

private:
	std::map<eventType, bool> states_;
	std::map<eventType, sf::FloatRect> rects_;
	sf::Vector2i location_;

};