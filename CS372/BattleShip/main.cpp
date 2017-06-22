/*
	main.cpp
	CS 372 Battleship Project
	By Frank Cline, Cameron Showalter
	2-8-17
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Game.h"
#include "Player.h"
#include "BoardSquare.h"
#include "Ship.h"

TEST_CASE("Ship Test")
{
	SECTION("Constructors and getters")
	{
		Ship s(2,4);
		REQUIRE(s.getHealth() == 8);
		REQUIRE(s.getWidth() == 2);
		REQUIRE(s.getHeight() == 4);
		REQUIRE(s.isDestroyed() == false);
	}
	SECTION("Placing ships")
	{
		Player p;
		Ship *s = new Ship(2,1);
		Ship *s2 = new Ship(3,1);
		REQUIRE(p.canPlaceShip(s,-1,-1) == false);
		REQUIRE(p.canPlaceShip(s,10,0) == false);
		REQUIRE(p.canPlaceShip(s,0,10) == false);
		REQUIRE(p.canPlaceShip(s,11,11) == false);
		REQUIRE(p.canPlaceShip(s,0,0) == true);
		REQUIRE(p.canPlaceShip(s,1,1) == true);
		REQUIRE(p.canPlaceShip(s,9,0) == false);
		REQUIRE(p.canPlaceShip(s,8,0) == true);

		REQUIRE(p.tryPlaceShipAt(s,0,0) == true);
		REQUIRE(p.tryPlaceShipAt(s2,0,0) == false);
		REQUIRE(p.tryPlaceShipAt(s2,1,0) == false);
		REQUIRE(p.tryPlaceShipAt(s2,2,0) == true);
	}
	SECTION("String to board coodinates")
	{
		Player p;
		pair<int,int> one_two = p.stringToBoardCoordinate("a2");
		REQUIRE(one_two.first == 0);
		REQUIRE(one_two.second == 1);
	}
}

TEST_CASE("Firing Test")
{
	SECTION("Off Board - Check for shots out of range")
	{
		Player player1;
		Player player2;

		REQUIRE(player1.selectSquare(-1,0) == nullptr);
        REQUIRE(player1.selectSquare(0,-1) == nullptr);
        REQUIRE(player1.selectSquare(12,0) == nullptr);
        REQUIRE(player1.selectSquare(0,12) == nullptr);
	}
    SECTION("On Board - Different board size")
    {
        const int WIDTH = 20;
        const int HEIGHT = 5;
        Player player1(WIDTH, HEIGHT);
        Player player2(WIDTH, HEIGHT);

        REQUIRE(player1.oppBoard[18][3].isSelected() == false); // square not yet hit
        player1.fire(player1.selectSquare(18,3)); // valid on new board
        REQUIRE(player1.oppBoard[18][3].isSelected() == true);  // square is now hit

        REQUIRE(player1.selectSquare(3,17) == nullptr);// not valid on new board
    }
    SECTION("HIT SHIPS - some ships are destroyed, some squares hit more than once")
    {
        //player 1 fires shots at player 2's placed ships
		Player player1;
		Player player2;
		Ship *s = new Ship(2,1);

        //  tryPlaceShipAt(Ship* ship, int x, int y)
        REQUIRE( player1.tryPlaceShipAt(s, 0, 0) == true);
    }
}

TEST_CASE("Game Test")
{
	SECTION("Create Game")
	{
		Game game;
		game.createGame();

		// Just so that Game class is created and no errors
		REQUIRE(true == true);
	}
}

