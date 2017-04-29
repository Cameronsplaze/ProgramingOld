#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "RoomData.hpp"


class RandomDungeon
{
public:
	RandomDungeon();
	enum direction {north, east, south, west};
	bool movePlayer(int dir);

	RoomData* currentRoomData();
	void setCurrentRoom(sf::Vector2i pos);
	void setCurrentRoom(std::size_t id);

	RoomData* getRoom(int x, int y);

	sf::Vector2i getGlobalPos();

	std::size_t roomCount() const;

	std::vector<RoomData*> rooms_;
private:
	std::size_t currentRoom_;

	int playersRoomX;
	int playersRoomY;

	int rndWidthHeight();
	int rndDoor();
	int rndRoom();
	void fixDoors();

	bool checkRoomExist(int x, int y);
	bool checkDoorOpen(int x, int y);
	std::size_t getRoomNumber();
};