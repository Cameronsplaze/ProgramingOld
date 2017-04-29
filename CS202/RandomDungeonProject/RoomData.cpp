#pragma once
#include <algorithm>
#include <vector>
#include <iostream>

#include "RoomData.hpp"

RoomData::RoomData() {}
RoomData::RoomData(int x, int y, int N, int E, int S, int W, int T)
{
	setX(x);
	setY(y);
	setDoorN(N);
	setDoorE(E);
	setDoorS(S);
	setDoorW(W);
	setType(T);
	isVisible = true;
	isRendered = false;
}

RoomData& RoomData::operator=(RoomData& rhs)
{
	width_ = rhs.getWidth();
	height_ = rhs.getHeight();

	x_ = rhs.getX();
	y_ = rhs.getY();

	doorN_ = rhs.getDoorN();
	doorE_ = rhs.getDoorE();
	doorS_ = rhs.getDoorS();
	doorW_ = rhs.getDoorW();
	type_ = rhs.getType();

	roomInfo_ = rhs.getRoomData();

	return (*this);
}

std::vector<int>& RoomData::getRoomData()
{
	return roomInfo_;
}

int RoomData::getX() { return x_; }
int RoomData::getY() { return y_; }
void RoomData::setX(int newX) { x_ = newX; }
void RoomData::setY(int newY) { y_ = newY; }

int RoomData::getDoorN() { return doorN_; } // if int == 0, no door
int RoomData::getDoorE() { return doorE_; } //        == 1, normal door
int RoomData::getDoorS() { return doorS_; } //        == 2, locked door - locked
int RoomData::getDoorW() { return doorW_; } //        == 3, locked door - unlocked
void RoomData::setDoorN(int newN) { doorN_ = newN; } // can add more doors as needed
void RoomData::setDoorE(int newE) { doorE_ = newE; }
void RoomData::setDoorS(int newS) { doorS_ = newS; }
void RoomData::setDoorW(int newW) { doorW_ = newW; }

int RoomData::getType() { return type_; };
void RoomData::setType(int newT) { type_ = newT; }

int RoomData::getRooomInfo(int i)
{
	return roomInfo_[i];
}
int RoomData::getRoomInfoSize()
{
	return roomInfo_.size();
}
//converts from Cameron's values to Alex's drawing values
int RoomData::converter(int cam)
{
	if (cam == 0)
	{
		return 1;
	}
	else if (cam == 1)
	{
		return 2;
	}
	return cam;
}


void RoomData::setRoomInfo(int width, int height)
{
	width_ = width;
	height_ = height;
	roomInfo_.resize(width_*height_);
	std::fill(roomInfo_.begin(), roomInfo_.end(), 0);
	//roomInfo_.clear(); //make sure there's nothing in it
	//int locationElement = 0;

	for (int w = 0; w < width_; w++)
	{
		for (int h = 0; h < height_; h++)
		{
			int id = w + h*width_;
			//Everything starts at a floor tile
			//roomInfo_.at(id) = blockType::floor;

			//The walls around a place
			if (w == 0 || w == (width_ - 1) || h == 0 || h == (height_ - 1))
			{
				roomInfo_.at(id) = 1;

				//If there should be a door there
				if (h == height_ / 2 && w == 0 && doorW_)
				{
					roomInfo_.at(id) = 2;
				}
				//If there should be a door there
				if (h == height_ / 2 && w == (width_ - 1) && doorE_)
				{
					roomInfo_.at(id) = 2;
				}
				//If there should be a door there
				if (w == width_ / 2 && h == 0 && doorN_)
				{
					roomInfo_.at(id) = 2;
				}
				//If there should be a door there
				if (w == width_ / 2 && h == (height_ - 1) && doorS_)
				{
					roomInfo_.at(id) = 2;
				}

			}
		}
	}
	//std::cout << (*this);
}

void RoomData::print(std::ostream& os) const
{
	for (int h = 0; h < height_; h++)
	{
		for (int w = 0; w < width_; w++)
		{
			os << roomInfo_.at(w + h*width_) << " ";
		}
		os << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const RoomData& lhs)
{
	lhs.print(os);
	return os;
}

int RoomData::getWidth() { return width_; }
int RoomData::getHeight() { return height_; }
void RoomData::setWidthHeight(int w, int h)
{
	width_ = w;
	height_ = h;
}