/*
Alex Medeiros
This is the Engine's function specific to level generation

*/
#include <list>
#include <cmath>

#include "Engine.hpp"
#include "Entity.hpp"
#include "Tileobjects.hpp"
#include "RandomDungeon.hpp"


namespace Tile
{
	sf::Vector2i grass(1, 1);
	sf::Vector2i brick(4, 3);
	sf::Vector2i door(7, 3);
	sf::Vector2i nulls(1, 1);

	//This is a map locating where all the sprites are for different objects
	std::vector<sf::Vector2i> tileVector =
	{
		grass, brick, door, nulls, nulls
	};
}

void Engine::updateLevel()
{
	//update the current player location
	playerLoc_ = player1.getLocation();
	globalLoc_ = dungeon.getGlobalPos();
	setCurrentRoom();
	loadChunk();
}

void Engine::setCurrentRoom()
{
	float x = player1.getLocation().x;
	float y = player1.getLocation().y;

	int dist = std::numeric_limits<int>::max();
	std::size_t newRoom;
	//find the closest room
	for (std::size_t id = 0; id < dungeon.roomCount(); id++)
	{
		float roomX = dungeon.rooms_[id]->getX()*MRS_f;
		float roomY = dungeon.rooms_[id]->getY()*MRS_f;
		float x12 = x - roomX;
		float y12 = y + roomY;
		int temp = sqrt(x12*x12 + y12*y12);
		//std::cout << "Attempt: " << id << " temp=" << temp << " dist=" << dist << std::endl;
		if (temp < dist)
		{
			dist = temp;
			newRoom = id;
		}
	}
	//sets the room to the new value
	dungeon.setCurrentRoom(newRoom);
}

//Not currently impliments
//should load only a few rooms around the player
//at the time performance is not a concern
void Engine::loadChunk()
{
	loadRoom();
}


void Engine::loadRoom()
{
	std::size_t roomID;
	
	//Find the room at this location
	//std::cout << "RoomCount: " << dungeon.roomCount() << std::endl;

	for (std::size_t roomID = 0; roomID < dungeon.roomCount(); roomID++)
	{
		//std::cout << "Looking for Position: " <<(int) dungeon.rooms_[roomID]->isVisible << std::endl;
		if (dungeon.rooms_[roomID]->isVisible && !dungeon.rooms_[roomID]->isRendered)
		{
			
			//This room is rendered and will not be rendered again
			dungeon.rooms_[roomID]->isRendered = true;
			
			if (dungeon.rooms_[roomID]->getDoorE());
				drawHall(WEST);
			
			unsigned int width = dungeon.rooms_[roomID]->getWidth();
			unsigned int height = dungeon.rooms_[roomID]->getHeight();

			sf::Vector2i size = { TILESIZE_i, TILESIZE_i };

			std::vector<int> roomVect(dungeon.rooms_[roomID]->getRoomData());

			for (unsigned int w = 0; w < width; w++)
				for (unsigned int h = 0; h < height; h++)
				{
					
					//This is a wall
					sf::Vector2f pos = { 
						(float) (w + MRS_f*dungeon.rooms_[roomID]->getX() - (float)dungeon.rooms_[roomID]->getWidth() / 2)*TILESIZE_f + TILESIZE_f / 2,
						(float) (h - MRS_f*dungeon.rooms_[roomID]->getY() - (float)dungeon.rooms_[roomID]->getHeight() / 2)*TILESIZE_f + TILESIZE_f / 2//Y is a negative for upward.
					};
					
					if (dungeon.rooms_[roomID]->getRoomData().at(w + h*width) == (int)Type::floor)
					{
						Floor *e = new Floor;
						sf::IntRect tile = { Tile::tileVector.at((int)Type::floor) * 32, size };
						sf::Vector2i room(dungeon.rooms_[roomID]->getX(), dungeon.rooms_[roomID]->getX());
						e->sprite_.setPosition(pos);
						e->sprite_.setTexture(tileTexture_);
						e->sprite_.setTextureRect(tile);
						e->setMyRoom(room);
						
						//std::cout << "Floor: ( " << dungeon.rooms_[roomID]->getX() << ", " << dungeon.rooms_[roomID]->getY() << std::endl;
						gameObjects_.push_back(e);

					}
					else if (dungeon.rooms_[roomID]->getRoomData().at(w + h*width) == (int)Type::wall)
					{
						Wall *e = new Wall;
						sf::IntRect tile = { Tile::tileVector.at((int)Type::wall) * 32, size };
						e->sprite_.setPosition(pos);
						e->sprite_.setTexture(tileTexture_);
						e->sprite_.setTextureRect(tile);
						e->setMyRoom(sf::Vector2i(dungeon.rooms_[roomID]->getX(), dungeon.rooms_[roomID]->getX()));

						gameObjects_.push_back(e);
					}
					//This is a door
					else if (dungeon.rooms_[roomID]->getRoomData().at(w + h*width) == (int)Type::door)
					{
						Door *e = new Door;
						sf::IntRect tile = { Tile::tileVector.at((int)Type::door) * 32, size };

						e->sprite_.setPosition(pos);
						e->sprite_.setTexture(tileTexture_);
						e->sprite_.setTextureRect(tile);
						e->setMyRoom(sf::Vector2i(dungeon.rooms_[roomID]->getX(), dungeon.rooms_[roomID]->getX()));

						gameObjects_.push_back(e);
					}
				}
		}
	}
}

void  Engine::drawHall(int dir)
{
	//creates a retroactive wall, Backward from the most recent room to the room traveled to.
	if (dir == WEST)
	{
		sf::Vector2f pos = {
			(float)(MRS_f*currentRoom_->getX() + (float)currentRoom_->getWidth() / 2)*TILESIZE_f + TILESIZE_f / 2,
			(float)(MRS_f*currentRoom_->getY())*TILESIZE_f + TILESIZE_f / 2//Y is a negative for upward.
		};

		int walls = 5;
		sf::Vector2i size = { TILESIZE_i, TILESIZE_i };

		for (int i = 1; i < walls; i++)
		{
			Wall *e = new Wall;
			sf::IntRect tile = { Tile::tileVector.at((int)Type::wall) * 32, size };
			e->sprite_.setPosition(sf::Vector2f(pos.x + TILESIZE_f * i, pos.y + 1.5f * TILESIZE_f));
			e->sprite_.setTexture(tileTexture_);
			e->sprite_.setTextureRect(tile);
			//e->setMyRoom(sf::Vector2i(dungeon.rooms_[roomID]->getX(), dungeon.rooms_[roomID]->getX()));

			gameObjects_.push_back(e);

			Wall *e2 = new Wall;
			e2->sprite_.setPosition(sf::Vector2f(pos.x + TILESIZE_f * i, pos.y - 2.5f * TILESIZE_f));
			e2->sprite_.setTexture(tileTexture_);
			e2->sprite_.setTextureRect(tile);
			//e->setMyRoom(sf::Vector2i(dungeon.rooms_[roomID]->getX(), dungeon.rooms_[roomID]->getX()));

			gameObjects_.push_back(e2);
		}

	}
}
