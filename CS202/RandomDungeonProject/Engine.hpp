#pragma once
/*
Alex Medeiros
Engine Class:
	Hold the gameplay features. 
	Loads Assets.
	User Inputs.

Split into Source files:
	Engine.cpp			//Updates, draws, and renders each frame. 
						//Gets and uses player input
	LevelEngine.cpp		//Manages the random dungeon entities

	DungeonMaster.cpp	//Manages all of the players, including enemies in the game room. 
*/

#include <SFML/Graphics.hpp>
#include <list>

#include "TextureManager.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "RandomDungeon.hpp"

class Engine
{
public:
	Engine();

	//Initiates the Engine and loads assets
	void go();

	//Holds the current level
	RandomDungeon dungeon;

	TextureManager texMan;

	Player player1;
	Enemy npc; 

	const float TILESIZE_f;
	const int TILESIZE_i;
	const float MRS_f;	//Max Room Size
	const int MRS_i;		//Max Room Size
	
protected:
	bool collisionCheck(sf::FloatRect rect, std::size_t id);
	bool useObject(sf::FloatRect rect);

private:
	std::size_t gameObjecCountID_;
	std::list<Entity*> gameObjects_;

	sf::RenderWindow window_;
	sf::View playerView_;

	sf::Clock clock_;
	sf::Texture tileTexture_;
	sf::Texture playerText_;

	RoomData* currentRoom_;
	std::vector<int> currentRoomVect_;
	std::vector<int> level_;

	float lastPress_;
	const float PRESSTIME;

	//=========Engine.cpp=======//
	bool init();
	void mainLoop();

	void loadTextures();
	void loadLevel();
	void mapUpdate();


	void processInput(const float dt);
	void update(const float dt);
	void renderFrame();

	void playerInput();
	void updatePlayer(const float dt);

	//=========LevelEngine.cpp=======//
	sf::Vector2i playerLoc_;
	sf::Vector2i globalLoc_;

	void updateLevel();
	void loadChunk();
	void loadRoom();
	void setCurrentRoom();
	void drawHall(int dir);

	//=========DungeonMaster.cpp=======//
	void updateDM(const float dt);

	void removePlayer(std::size_t id);
	void addPlayer(Player* play);
	void playerTurns(const float dt);
	bool attack(Player* attacker, sf::Vector2i loc);
	std::list<Player*> players_;

	bool combat_;
};
