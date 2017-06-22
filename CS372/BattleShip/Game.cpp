/*
    Game.cpp
    CS 372 Battleship Project
    By Frank Cline, Cameron Showalter
    2-28-17
*/

#include "Game.h"
#include <iostream>
#include <istream>

Game::~Game()
{
    if (player1)
    {
        delete player1;
    }
    if (player2)
    {
        delete player2;
    }
}

void Game::createGame()
{
    printMainScreen();
    std::cin.get();  //waits for user to press enter

    createPlayers();
    placeShips();

    if (player1->hasQuit() || player2->hasQuit())
    {
        if (playAgain())
	    {
	    	restartGame();
	    }
	    return;
    }

    current_player = player1;
    other_player = player2;

	printPassingScreen();
	std::cin.get();  //waits for user to press enter

    gameLoop();

    if (playAgain())
    {
    	restartGame();
    }
}

bool Game::playAgain()
{
	string input;
	cout << "Play again? (Type \"y\" for yes)" << endl;
	cout << "--> ";
	getline(cin,input);
	return (input == "y");
}

void Game::restartGame()
{
	if (player1)
	{
		delete player1;
	}
	if (player2)
	{
		delete player2;
	}
	createGame();
}

void Game::createPlayers()
{
    player1 = new Player("Player 1");
    player2 = new Player("Player 2");
}

void Game::placeShips()
{
    player1->placeShips();
    player2->placeShips();

    player1->oppBoard = player2->playerBoard;
    player2->oppBoard = player1->playerBoard;
}

void Game::gameLoop()
{
    while(true)
    {
        current_player->playerBoard = other_player->oppBoard;
        current_player->takeTurn();

        if (current_player->hasQuit())
        {
            return;
        }
        else if (current_player->hasHitShip())
        {
            if (other_player->hasLost())
            {
                cout << current_player->getName() << " won!" << endl;
                return;
            }
            else
            {
                continue;
            }
        }

        nextPlayerTurn();

        printPassingScreen();
        std::cin.get();  //waits for user to press enter
    }
}

void Game::nextPlayerTurn()
{
    Player *oldcurrent = current_player;
    current_player = other_player;
    other_player = oldcurrent;
}

void Game::printMainScreen()
{
    cout <<"********************(Make Sure you can See this Line)********************" << endl;
    cout <<"   " << endl;
    cout <<"   " << endl;
    cout <<"                        WELCOME TO BATTLESHIP" << endl;
    cout <<"                      (Press ENTER to continue)" << endl;
    cout <<"       " << endl;
    cout <<"                       (Type \"quit\" to quit) " << endl;
    cout <<" ^      " << endl;
    cout <<"/|\\     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<" |     " << endl;
    cout <<"*********(Make sure you can see the very top line, and this one)*********" << endl;

}
void Game::printPassingScreen()
{
    cout <<"*************************************************************************" << endl;
    cout << endl;
    cout <<"           Give " << current_player->getName() << " the computer and Press ENTER to continue" << endl;
    cout << endl;
    cout <<"                   |        |       " << endl;
    cout <<"                 |-|-|      |       " << endl;
    cout <<"                   |        |       " << endl;
    cout <<" ^                 | {O}    |       " << endl;
    cout <<"/|\\                '--|     |       " << endl;
    cout <<" |                  .|]_   |        " << endl;
    cout <<" |            _.-=.' |     |        " << endl;
    cout <<" |           |    |  |]_   |        " << endl;
    cout <<" |           |_.-='  |   __|__      " << endl;
    cout <<" |            _.-='  |\\   /|\\       " << endl;
    cout <<" |           |    |  |-'-'-'-'-.    " << endl;
    cout <<" |           |_.-='  '========='    " << endl;
    cout <<" |                `   |     |       " << endl;
    cout <<" |                 `. |    / \\      " << endl;
    cout <<" |                   ||   /   \\____.--=''''==--.._     " << endl;
    cout <<" |             _.-='  |\\   /|\\             ||_.'--==' " << endl;
    cout <<" |                   ||  |    |    |\\ ||  ||  || |                        ___" << endl;
    cout <<" |      ____         ||__|____|____| \\||__||__||_/    __________________/|   |" << endl;
    cout <<" |     |    |______  |===.---. .---.========''''=-._ |     |     |     / |   |" << endl;
    cout <<" |     |    ||     |\\| |||   | |   |      '===' ||  \\|_____|_____|____/__|___|" << endl;
    cout <<" |     |-.._||_____|_\\___'---' '---'______....---===''======//=//////========|" << endl;
    cout <<" |     |--------------\\------------------/-----------------//-//////---------/" << endl;
    cout <<" |     |               \\                /                 // //////         /" << endl;
    cout <<" |     |                \\______________/                 // //////         /" << endl;
    cout <<" |     |                                        _____===//=//////=========/" << endl;
    cout <<" |     |=========================================================USS Dora/" << endl;
    cout <<" |     '----------------------------------------------------------------`" << endl;
    cout <<"*************************************************************************" << endl;
}

