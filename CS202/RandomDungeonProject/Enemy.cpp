#include "Enemy.hpp"



Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::update(Event& e, const float dt)
{
	if (!e.getState(COLLISION))
	{
		//No collision, can move again
		currentPos = nextPos;
		//sprite_.setPosition(currentPos);
	}

	//If there was a collison reset the player position
	sprite_.setPosition(currentPos);

	updateLocation();
}

void Enemy::handleInput(Event& e, const float dt)
{
	lastPress_ += dt;

	//Resets where the palyer should be
	currentPos = sprite_.getPosition();
	nextPos = currentPos;

	//ORDER MATTERS, dont want player moivng and then checking door.
	if (lastPress_ >= PRESSTIME)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
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
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			lastPress_ = 0;
			nextPos.y -= TILESIZE_i;
			sprite_.setTextureRect(sf::IntRect(TILESIZE_i*4, 3 * TILESIZE_i, TILESIZE_i, TILESIZE_i));
			facing = NORTH;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		{
			lastPress_ = 0;
			nextPos.y += TILESIZE_i;
			sprite_.setTextureRect(sf::IntRect(TILESIZE_i * 4, 0 * TILESIZE_i, TILESIZE_i, TILESIZE_i));
			facing = SOUTH;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			lastPress_ = 0;
			nextPos.x -= TILESIZE_i;
			sprite_.setTextureRect(sf::IntRect(TILESIZE_i * 4, 1 * TILESIZE_i, TILESIZE_i, TILESIZE_i));
			facing = WEST;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		{
			lastPress_ = 0;
			nextPos.x += TILESIZE_i;
			sprite_.setTextureRect(sf::IntRect(TILESIZE_i * 4, 2 * TILESIZE_i, TILESIZE_i, TILESIZE_i));
			facing = EAST;
		}
	}
	sprite_.setPosition(nextPos);
	if (currentPos != nextPos)
	{
		e.setRect(COLLISION, sprite_.getGlobalBounds());
	}
}
