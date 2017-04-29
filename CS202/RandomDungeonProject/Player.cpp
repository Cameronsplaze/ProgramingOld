/*
Alex Medeiros
Player:
	Parent of the Enemy class. 
	The class overlays the entity class. 
	Player gives more functionality that is needed for the game.
*/
#include <iostream>

#include "Player.hpp"
#include "Entity.hpp"
#include "Event.hpp"

Player::Player(): TILESIZE_f(32.0f), TILESIZE_i(32), lastPress_(0.0f), PRESSTIME(0.1f)
{
	Event e;
	update(e, 0);
	//Character Initiation
	this->rollStats();

	Dice* d = new Dice(8);
	baseAttack.setBAB(3);
	//baseAttack.setDamage(getAttribute("STR"));
	baseAttack.setDamage(1);
	baseAttack.setAttackDice(d);
}

bool Player::isDead()
{
	return dead_;
}

void Player::update(Event& e, const float dt)
{
	if (!e.getState(COLLISION))
	{
		//No collision, can move again
		currentPos = nextPos;
		//sprite_.setPosition(currentPos);
	}
	
	//If there was a collison reset the player position
	sprite_.setPosition(currentPos);
	
	playerView.setCenter(sprite_.getPosition());
	updateLocation();

	if (this->getHP() <= 0)
	{
		//std::cout << "PLAYER DEAD!" << std::endl;
		dead_ = true;
	}
}

bool Player::turn()
{
	return turn_;
}

void Player::setTurn(bool t)
{
	turn_ = t;
}
void Player::handleInput(Event& e, const float dt)
{
	lastPress_ += dt;

	//Resets where the palyer should be
	currentPos = sprite_.getPosition();
	nextPos = currentPos;

	//ORDER MATTERS, dont want player moivng and then checking door.
	if (lastPress_ >= PRESSTIME)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			lastPress_ = 0;
			sf::FloatRect rect(getBoundingBox());

			switch (facing)
			{
			case NORTH:
				rect.top -= TILESIZE_i;
				break;
			case SOUTH:
				rect.top += TILESIZE_i;
				break;
			case EAST:
				rect.left += TILESIZE_i;
				break;
			case WEST:
				rect.left -= TILESIZE_i;
				break;
			}
			//Sets the rectangle for the next 
			e.setRect(USEOBJECT, rect);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			lastPress_ = 0;
			nextPos.y -= TILESIZE_i;
			sprite_.setTextureRect(sf::IntRect(TILESIZE_i, 3 * TILESIZE_i, TILESIZE_i, TILESIZE_i));
			facing = NORTH;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			lastPress_ = 0;
			nextPos.y += TILESIZE_i;
			sprite_.setTextureRect(sf::IntRect(TILESIZE_i, 0 * TILESIZE_i, TILESIZE_i, TILESIZE_i));
			facing = SOUTH;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			lastPress_ = 0;
			nextPos.x -= TILESIZE_i;
			sprite_.setTextureRect(sf::IntRect(TILESIZE_i, 1 * TILESIZE_i, TILESIZE_i, TILESIZE_i));
			facing = WEST;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			lastPress_ = 0;
			nextPos.x += TILESIZE_i;
			sprite_.setTextureRect(sf::IntRect(TILESIZE_i, 2 * TILESIZE_i, TILESIZE_i, TILESIZE_i));
			facing = EAST;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			lastPress_ = 0;
			sf::Vector2i loc(getLocation());
			sf::FloatRect rect(getBoundingBox());

			switch (facing)
			{
			case NORTH:
				loc.y -= 1;
				break;
			case SOUTH:
				loc.y += 1;
				break;
			case EAST:
				loc.x += 1;
				break;
			case WEST:
				loc.x -= 1;
				break;
			}
			//Sets the rectangle for the next 
			e.setLocation(loc);
			e.setState(ATTACK, true);
		}
	}
	sprite_.setPosition(nextPos);
	if (currentPos != nextPos)
	{
		e.setRect(COLLISION, sprite_.getGlobalBounds());
	}
}

void Player::updateLocation()
{
	sf::Vector2f temp = this->currentPos;
	temp.x = temp.x / 32;
	temp.y = temp.y / 32;
	location_ = sf::Vector2i((int)temp.x, (int)temp.y);
}

sf::Vector2i Player::getLocation() const
{
	return location_;
}