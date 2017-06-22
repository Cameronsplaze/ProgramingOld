
/*
	Player.h
	CS 372 Battleship Project
	By Frank Cline, Cameron Showalter
	2-8-17
*/

#ifndef GAME_H
#define GAME_H

#include "Ship.h"
#include "BoardSquare.h"
#include "Player.h"

class Game
{
private:
    Player *player1, *player2;
    Player *current_player, *other_player;

public:
    ~Game();

    void createGame();
    void createPlayers();
    void placeShips();

    void gameLoop();
    void nextPlayerTurn();

	bool playAgain();
	void restartGame();
    
    void printMainScreen();
    void printPassingScreen();
};

#endif
