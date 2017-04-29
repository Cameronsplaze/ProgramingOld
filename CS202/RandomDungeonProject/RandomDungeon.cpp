#pragma once

#include "RandomDungeon.hpp"
#include "RoomData.hpp"
#include "Engine.hpp"

#include <sstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>


RandomDungeon::RandomDungeon():currentRoom_(0), playersRoomX(0), playersRoomY(0)
{
	RoomData* newData = new RoomData(0, 0, 1, 1, 1, 1, 0);
	rooms_.push_back(newData); //creates spawn+
 	rooms_[0]->setRoomInfo(13, 13); //spawn is 15 width x 15 height
	currentRoom_ = 0;
}


RoomData* RandomDungeon::currentRoomData()
{
	return rooms_[currentRoom_];
}

void RandomDungeon::setCurrentRoom(std::size_t id)
{
	currentRoom_ = id;
	playersRoomX = this->rooms_[id]->getX();
	playersRoomY = this->rooms_[id]->getY();
}
void RandomDungeon::setCurrentRoom(sf::Vector2i pos)
{
	for (std::size_t i = 0; i < rooms_.size(); i++)
	{
		if (rooms_[i]->getY() == pos.y && rooms_[i]->getX() == pos.x)
		{
			//std::cout << "current Room Found" << std::endl;
			currentRoom_ = i;
			playersRoomX = rooms_[i]->getX();
			playersRoomY = rooms_[i]->getY();
		}
			
	}
}

int RandomDungeon::rndWidthHeight()
{
	int rn = rand() % 6 + 10;
	//While rn is even
	while (!(rn % 2))
	{
		rn = rand() % 6 + 10;
	}

	return rn;
}
bool RandomDungeon::checkRoomExist(int x, int y)
{
	for (std::size_t i = 0; i<rooms_.size(); i++)
	{
		if (rooms_[i]->getY() == (y)&& rooms_[i]->getX() == (x))
		{
			//room does exist.
			return true;
		}
	}
	return false;
}

RoomData* RandomDungeon::getRoom(int x, int y)
{
	for (std::size_t i = 0; i<rooms_.size(); i++)
	{
		if (rooms_[i]->getY() == (y) && rooms_[i]->getX() == (x))
		{
			//room does exist.
			return rooms_[i];
		}
	}
	return false;
}
std::size_t RandomDungeon::getRoomNumber()
{
	for (std::size_t i = 0; i<rooms_.size(); i++)
	{
		if (rooms_[i]->getY() == (playersRoomY) && rooms_[i]->getX() == (playersRoomX))
		{
			//room does exist.
			return i;
		}
	}
}
sf::Vector2i RandomDungeon::getGlobalPos()
{
	return sf::Vector2i(playersRoomX, playersRoomY);
}

bool RandomDungeon::checkDoorOpen(int x, int y)
{
	for (int i = 0; i<rooms_.size(); i++)
	{
		if (rooms_[i]->getY() == x)
		{
			if (rooms_[i]->getX() == y)
			{
				//found right element/room
				if (rooms_[i]->getDoorN() == 1 || rooms_[i]->getDoorN() == 3)//add more open door type here. (all doors are closed by default)
				{
					//door is open
					return true;
				}
				else { //Bad door error?
				}
			}
		}
	}
	return false;
}

bool RandomDungeon::movePlayer(int dir)
{
	bool roomExist = false;
	bool openDoor = true;

	if (dir == north)
	{
		//Checks to see if the room exists
		roomExist = checkRoomExist(playersRoomX, playersRoomY + 1);

		//checks for "open" doors
		openDoor = checkDoorOpen(playersRoomX, playersRoomY);
		openDoor = true;

		//std::cout << "Room Exist: " << roomExist << " openDoor: " << openDoor;
		//if room exists...
		if ((roomExist == true) && (openDoor == true))
		{
			currentRoom_ = getRoomNumber();
		}
		//if room does not exist yet
		else if ((roomExist == false) && (openDoor == true))
		{
			RoomData* myData = new RoomData(playersRoomX, playersRoomY + 1, rndDoor(), rndDoor(), 1, rndDoor(), rndRoom());
			rooms_.push_back(myData); //temp  -last 4 int's represent doors -very last is room type
			fixDoors();
			rooms_.back()->setRoomInfo(rndWidthHeight(), rndWidthHeight());
			currentRoom_ = rooms_.size();
		}

		return false;
	}
	if (dir == west)
	{
		//Checks to see if the room exists
		roomExist = checkRoomExist(playersRoomX-1, playersRoomY);

		//checks for "open" doors
		openDoor = checkDoorOpen(playersRoomX, playersRoomY);
		openDoor = true;
		//if room exists...
		if ((roomExist == true) && (openDoor == true))
		{
			currentRoom_ = getRoomNumber();
		}
		//if room does not exist yet
		else if ((roomExist == false) && (openDoor == true))
		{
			RoomData* myData = new RoomData(playersRoomX - 1, playersRoomY, rndDoor(), 1, rndDoor(), rndDoor(), rndRoom());
			rooms_.push_back(myData); //temp  -last 4 int's represent doors -very last is room type
			fixDoors();
			rooms_.back()->setRoomInfo(rndWidthHeight(), rndWidthHeight());
			currentRoom_ = rooms_.size();
		}
		return false;
	}
	if (dir == south)
	{
		//Checks to see if the room exists
		roomExist = checkRoomExist(playersRoomX, playersRoomY - 1);

		//checks for "open" doors
		openDoor = checkDoorOpen(playersRoomX, playersRoomY);
		openDoor = true;
		//if room exists...
		if ((roomExist == true) && (openDoor == true))
		{
			currentRoom_ = getRoomNumber();
		}
		//if room does not exist yet
		else if ((roomExist == false) && (openDoor == true))
		{
			RoomData* myData = new RoomData(playersRoomX, playersRoomY - 1, 1, rndDoor(), rndDoor(), rndDoor(), rndRoom());
			rooms_.push_back(myData); //temp  -last 4 int's represent doors -very last is room type
			fixDoors();
			rooms_.back()->setRoomInfo(rndWidthHeight(), rndWidthHeight());
			currentRoom_ = rooms_.size();
		}
		return false;
	}
	if (dir == east)
	{
		//Checks to see if the room exists
		roomExist = checkRoomExist(playersRoomX + 1, playersRoomY);

		//checks for "open" doors
		openDoor = checkDoorOpen(playersRoomX, playersRoomY);
		openDoor = true;
		//if room exists...
		if ((roomExist == true) && (openDoor == true))
		{
			currentRoom_ = getRoomNumber();
		}
		//if room does not exist yet
		else if ((roomExist == false) && (openDoor == true))
		{
			RoomData* myData = new RoomData(playersRoomX + 1, playersRoomY, rndDoor(), rndDoor(), rndDoor(), 1, rndRoom());
			rooms_.push_back(myData); //temp  -last 4 int's represent doors -very last is room type
			fixDoors();
			rooms_.back()->setRoomInfo(rndWidthHeight(), rndWidthHeight());
			currentRoom_ = rooms_.size();
		}
		return false;
	}

	return false;
}
//generates what the door will be
int RandomDungeon::rndDoor()
{
	//add method that checks to see if the future room already exists and what door it has
	int returnMe;
	int randomValue = rand() % 100 + 1;
	//return 1; //temp
	if (rooms_.size()<10) {
		if (randomValue < 25)
		{
			returnMe = 0; //no door (1/3 chance)
		}
		else
		{
			returnMe = 1; //normal door(2/3 chance)
		}
	}
	else if (rooms_.size()<15) {
		if (randomValue < 40)
		{
			returnMe = 0; //no door (1/3 chance)
		}
		else
		{
			returnMe = 1; //normal door(2/3 chance)
		}
	}
	else if (rooms_.size()<20) {
		if (randomValue < 50)
		{
			returnMe = 0; //no door (1/3 chance)
		}
		else
		{
			returnMe = 1; //normal door(2/3 chance)
		}
	}
	else {
		if (randomValue < 55)
		{
			returnMe = 0; //no door (1/3 chance)
		}
		else
		{
			returnMe = 1; //normal door(2/3 chance)
		}
	}
	//may add other doors later. if door is passable (not locked), then you need to add it to
	//4 different if statements below.

	//cout << "randomReturn: " << returnMe << " randomValue: " << randomValue << endl;
	//return 1;

	return returnMe;
}

//randomly picks what type of room is generated(1-9) only spawn is type 0.
int RandomDungeon::rndRoom()
{
	//I wrote it like this so we could control which rooms were more / less lucky
	int randomValue = rand() % 100 + 1;
	int returnMe;
	if (randomValue < 20)
	{
		returnMe = 1;
	}
	else if (randomValue < 30)
	{
		returnMe = 2;
	}
	else if (randomValue < 40)
	{
		returnMe = 3;
	}
	else if (randomValue < 50)
	{
		returnMe = 4;
	}
	else if (randomValue < 60)
	{
		returnMe = 5;
	}
	else if (randomValue < 70)
	{
		returnMe = 6;
	}
	else if (randomValue < 80)
	{
		returnMe = 7;
	}
	else if (randomValue < 90)
	{
		returnMe = 8;
	}
	else
	{
		returnMe = 9;
	}

	return returnMe;
}

//if two rooms are generated side by side but the door between them isn't the reason they generated, it has a chance of
//one room having a door and the other not, making a "one way" door. this method changes them both to what the first one was.
void RandomDungeon::fixDoors()
{
	//rooms[rooms.size()-1]->getX()
	int roomX = rooms_.back()->getX();
	int roomY = rooms_.back()->getY();
	for (int i = 0; i<rooms_.size(); i++)
	{
		//finds if there are any rooms already generated to the right, left, down, and/or up from new room
		if (roomX == rooms_[i]->getX() || roomY == rooms_[i]->getY())
		{
			//same exact code in this if and the else if below it
			if (roomX + 1 == rooms_[i]->getX() || roomY + 1 == rooms_[i]->getY() || roomX - 1 == rooms_[i]->getX() || roomY - 1 == rooms_[i]->getY())
			{
				int roomX = rooms_[rooms_.size() - 1]->getX();
				int roomY = rooms_[rooms_.size() - 1]->getY();
				//found room left
				if (rooms_[i]->getX() == roomX + 1)
				{
					rooms_[rooms_.size() - 1]->setDoorE(rooms_[i]->getDoorW());
				}
				//found room right
				if (rooms_[i]->getX() == roomX - 1)
				{
					rooms_[rooms_.size() - 1]->setDoorW(rooms_[i]->getDoorE());

				}
				//found room above
				if (rooms_[i]->getY() == roomY + 1)
				{
					rooms_[rooms_.size() - 1]->setDoorN(rooms_[i]->getDoorS());

				}
				//found room below
				if (rooms_[i]->getY() == roomY - 1)
				{
					rooms_[rooms_.size() - 1]->setDoorS(rooms_[i]->getDoorN());

				}
			}
		}
	}
}


std::size_t RandomDungeon::roomCount() const
{
	return rooms_.size();
}
