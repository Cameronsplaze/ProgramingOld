/*
    Player.cpp
    CS 372 Battleship Project
    By Frank Cline, Cameron Showalter
    2-8-17
*/

#include "Player.h"
#include <string>
#include <sstream>

string Player::getName()
{
	return name_;
}

bool Player::hasLost()
{
    for(auto i=0; i<shiplist.size(); ++i)
    {
        if( !shiplist[i]->isDestroyed() )
        {
            return false;
        }
    }
    return true;
}
void Player::printBoards()
{
    cout << "\n***** " << name_ << " *****\n" << endl;
    printPlayerBoard();
    cout << "\n***** Opponent Board *****\n" << endl;
    printOppBoard();
}

void Player::printPlayerBoard()
{
	cout << setw(3)<< " ";
    for(auto i=0; i<widthBoard_; ++i)
    {
        cout << setw(3)<< " " << (char)(i+65);
    }
    cout << endl;
    for(auto i=0; i<heightBoard_; ++i)
    {
        cout << setw(3) << (i+1) << " ";
        for(auto g=0; g<widthBoard_; ++g)
        {
            cout << setw(3) << playerBoard[g][i].printPlayerSquare() << " ";
        }
        cout << endl;
    }
}

void Player::printOppBoard()
{
	cout << setw(3)<< " ";
    for(auto i=0; i<widthBoard_; ++i)
    {
        cout << setw(3)<< " " << (char)(i+65);
    }
    cout << endl;
    for(auto i=0; i<heightBoard_; ++i)
    {
        cout << setw(3) << (i+1) << " ";
        for(auto g=0; g<widthBoard_; ++g)
        {
            cout << setw(3) << oppBoard[g][i].printOppSquare() << " ";
        }
        cout << endl;
    }
}
//++++++++++++++++++++++++++++PLACESHIP HANDLE++++++++++++++++++++++++++++
void Player::placeShips()
{
    vector<int> shipSizes {5,4,3,3,2};

    for (auto i=0; i<shipSizes.size(); ++i)
    {
        Ship *s = nullptr;

        while (true)
        {
        	cout << "Placing ship of length: " << shipSizes[i] << endl;
            printBoards();
            cout << "Placing ship of length: " << shipSizes[i] << endl;
            cout << "Insert \'h\' or \'v\' before coordinate for horizontal or "
            << "vertical orientation (i.e. va1)." << endl;
            cout << "Will place from left to right, or up to down." << endl;

            string input = getUserInput();
            if (input == "quit")
            {
                quit_ = true;
                return;
            }
            else if (input.length() > 2)
            {
            	if (tolower(input.at(0)) == 'v' && 
            		isValidInput(input.substr(1,input.length()-1)))
            	{
            		s = new Ship(1,shipSizes[i]);
            	}
            	else if (tolower(input.at(0)) == 'h' && 
            			 isValidInput(input.substr(1,input.length()-1)))
            	{
            		s = new Ship(shipSizes[i],1);
            	}
            	else
            	{	
            		cout << "\n\n +++ Invalid input +++ \n" << endl;
            		continue;
            	}

            	pair<int,int> coordinates = stringToBoardCoordinate(input.substr(1,input.length()-1));
                int x = coordinates.first;
                int y = coordinates.second;
                if (canPlaceShip(s,x,y))
                {
                    placeShip(s,x,y);
                    break;
                }
                else
                {
                    delete s;
                }
            }
            cout << "\n\n +++ Invalid input +++ \n" << endl;
        }
    }
}

pair<int,int> Player::stringToBoardCoordinate(string input)
{
    int x,y;
    int length_of_num = input.length()-1;

    x = tolower(input.at(0)) - 'a';
    y = stringToInt(input.substr(1,length_of_num));
    y -= 1; // y-1 because a1 -> board[0][0]

    return make_pair(x,y);
}

bool Player::tryPlaceShipAt(Ship* ship, int x, int y)
{
    if(canPlaceShip(ship, x, y))
    {
        placeShip(ship, x, y);
    }
    else
    {
        return false;
    }
    return true;
}

bool Player::canPlaceShip(Ship* ship, int x, int y)
{
    if(ship->getWidth() <= 0 || ship->getHeight() <=0 ||
        x < 0 || y < 0)
    {
        return false;
    }
    if (x+ship->getWidth() > widthBoard_ ||
             y+ship->getHeight() > heightBoard_)
    {
        return false;
    }
    for (auto i=x; i < x+ship->getWidth(); ++i)
    {
        for (auto j=y; j < y+ship->getHeight(); ++j)
        {
            if (playerBoard[i][j].squareShip())
            {
                return false;
            }
        }
    }
    return true;
}

void Player::placeShip(Ship* ship, int x, int y)
{
    int height = ship->getHeight();
    int width = ship->getWidth();

	for (auto i=0; i<width; ++i)
	{
		for (auto j=0; j<height; ++j)
		{
			playerBoard[x][y].addShip(ship);
			++y;
		}
		y -= height;
		++x;
	}
	shiplist.push_back(ship);
}

//++++++++++++++++++++++++++++FIRE AT SHIP HANDLE++++++++++++++++++++++++++++

bool Player::canFire(BoardSquare *square)
{
    if (square->isSelected())
	{
		cout << "Invalid selection." << endl;
		return false;
	}

return true;
}
void Player::fire(BoardSquare *square)
{
    square->Hit();
}

//++++++++++++++++++++++++++++TAKE TURN++++++++++++++++++++++++++++

void Player::takeTurn()
{
    shiphit_ = false;
    printBoards();

    string input = getUserInput();

    if (input == "quit")
    {
        quit_ = true;
        return;
    }
    else if (isValidInput(input))
    {
        BoardSquare *square = stringToBoardSquare(input);
        if (!canFire(square))
        {
            cout << "You've already fired there!" << endl;
            takeTurn();
            return;
        }

        fire(square);

        if(square->squareShip())
        {
            if (square->squareShip()->isDestroyed())
            {
                cout << "You sunk their ship!" << endl;
            }
            else
            {
                cout << "You hit a ship!!" << endl;
            }
            shiphit_ = true;
        }
        else
        {
            cout << "You missed" << endl;
        }
    }
    else
    {
        cout << "Invalid command." << endl;
        takeTurn();
    }
}

string Player::getUserInput()
{
    string input;
    cout << "Input coordinates to select (i.e. a1)" << endl;
    cout << "--> ";
    getline(cin,input);
    return input;
}

bool Player::isValidInput(const string & input)
{
    if (input.length() < 2 )
    {
        return false;
    }
    else if (tolower(input.at(0)) < 'a' ||
             tolower(input.at(0)) >= ('a' + heightBoard_))
    {
        return false;
    }
    else
    {
        try
        {
            int x = stringToInt(input.substr(1,input.length()));
            if (x > 0 && x <= heightBoard_)
            {
                return true;
            }
            else
            {
               return false;
            }
        }
        catch (...)
        {
            return false;
        }
    }
}

BoardSquare * Player::stringToBoardSquare(const string & input)
{
    int x,y;

    x = tolower(input.at(0)) - 'a';
    y = stringToInt(input.substr(1,input.length())) - 1; // y-1 because a1 -> board[0][0]

    return &oppBoard[x][y];
}

bool Player::hasQuit()
{
    return quit_;
}

bool Player::hasHitShip()
{
    return shiphit_;
}

BoardSquare * Player::selectSquare(int x, int y)
{
    if (x >= 0 && x < widthBoard_ && y >= 0 && y < heightBoard_)
    {
        return &oppBoard[x][y];
    }
    else
    {
        return nullptr;
    }
}
int Player::stringToInt(string text)
{
    int result;
    std::stringstream convert(text);

    if( !(convert >> result) )
    {
        return -1;
    }
    return result;
}
