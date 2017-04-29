/*
Alex Medeiros
Entity:
	All Objects in the game dirive from this class
	Includes a sprite, id, and hitbox
*/
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>

//north being up and east being right
enum Pos {NORTH, EAST, SOUTH, WEST};
enum class Type {null=-1, floor=0, wall=1, door=2};

class Entity: public sf::Drawable, public sf::Transformable
{
public:
	Entity();
	virtual void use() = 0;

	sf::FloatRect getBoundingBox();

	sf::Vector2f currentPos;
	sf::Vector2f nextPos;

	void setID(std::size_t id);
	std::size_t getID();

	sf::Sprite sprite_;

	void draw(sf::RenderWindow wind);

	bool canUse();
	bool isSolid();

	sf::Vector2i getMyRoom();
	void setMyRoom(sf::Vector2i pos);

	//Used for characters that move and updating their spirte
	Pos facing;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
	sf::FloatRect hitBox_;
	std::size_t id_;

	bool solid_;
	bool visible_;
	bool canUse_;

	std::size_t roomID_;
	sf::Vector2i myRoom_;
};

