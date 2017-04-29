#pragma once



#include<vector>
#include<iostream>

class RoomData {
public:
	RoomData();
	RoomData(int x, int y, int N, int E, int S, int W, int T);
	
	std::vector<int>& getRoomData();

	enum blockType { floor=0, wall=1, door=2 };
	enum doorType { noDoor, normalDoor, lockedDoor, unlockedDoor };

	RoomData& operator=(RoomData& rhs);

	void print(std::ostream& os) const;
	friend std::ostream& operator<<(std::ostream& os, const RoomData& lhs);

	bool isRendered;
	bool isVisible;
	std::size_t roomID_;

	int getX();
	int getY();

	int getDoorN(); // if int == 0, no door
	int getDoorE(); //        == 1, normal door
	int getDoorS(); //        == 2, locked door - locked
	int getDoorW(); //        == 3, locked door - unlocked
	int getType();
	void setType(int newT);

	//for drawing the room
	int getRooomInfo(int i);
	int getRoomInfoSize();
	int getWidth();
	int getHeight();

	void setX(int newX);
	void setY(int newY);
	void setDoorN(int newN);
	void setDoorE(int newE);
	void setDoorS(int newS);
	void setDoorW(int newW);
	void setWidthHeight(int w, int h);
	//converts from Cameron's values to Alex's drawing values
	int converter(int cam);
	//also for drawing the room
	void setRoomInfo(int width, int height);
private:

	std::vector<int> roomInfo_;

	int width_=10;
	int height_=10;

	int x_=0;
	int y_=0;
	int doorN_=0; // North, East, South, West
	int doorE_=0;
	int doorS_=0;
	int doorW_=0;
	int type_=0;
};

std::ostream& operator<<(std::ostream& os, const RoomData& lhs);