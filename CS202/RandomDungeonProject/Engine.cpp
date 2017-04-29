#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Engine.hpp"
#include "Tileobjects.hpp"
#include "Player.hpp"
#include "Event.hpp"


Engine::Engine(): TILESIZE_f(32.0f), TILESIZE_i(32), lastPress_(0), MRS_f(16.0f), MRS_i(16), PRESSTIME(0.1f), gameObjecCountID_(0), combat_(false)
{
	//loads the level to current room data
	currentRoom_ = dungeon.currentRoomData();
	currentRoomVect_ = currentRoom_->getRoomData();

	player1.sprite_.setTexture(playerText_);
	player1.sprite_.setTextureRect(sf::IntRect(0, 0, 32, 32));
	player1.sprite_.setPosition(sf::Vector2f(0, 0));
	player1.setTurn(true);
	Event e;
	player1.update(e, 0);
	

	addPlayer(&player1);
	addPlayer(&npc);


	npc.sprite_.setTexture(playerText_);
	npc.sprite_.setTextureRect(sf::IntRect(4*32, 0, 32, 32));
	npc.sprite_.setPosition(sf::Vector2f(3*32, 0));


	loadTextures();
}

void Engine::go()
{
	//Sets a random seed for the dice function
	unsigned int time_ui = (unsigned int) (time(NULL));
	srand(time_ui);

	//Trys to Create a window and returns an error if it cant
	if (!init())
	{
		std::cout << "Failed to Initialize Engine. " << std::endl;
		throw("Could not initialize Engine");
	}

	mainLoop();
}

bool Engine::init()
{
	window_.create(sf::VideoMode(1280, 720, 32), "RPG");
	window_.setFramerateLimit(60);

	//Rectangle (Left, Right, Width, Height
	playerView_.reset(sf::FloatRect(200, 200, 800, 450));
	player1.playerView.reset(sf::FloatRect(0, 0, 800, 450));
	playerView_.setCenter(sf::Vector2f(0, 0));
	

	loadLevel();
	//generateWall();

	if (!window_.isOpen())
	{
		return false;
	}

	return true;
}

float getFPS(const sf::Time& time) {
	return (1000000.0f / time.asMicroseconds());
}
void Engine::mainLoop()
{
	while (window_.isOpen())
	{
		sf::Time elapsed = clock_.restart();
		float dt = elapsed.asSeconds();

		processInput(dt);
		update(dt);
		renderFrame();
		//std::cout << getFPS(elapsed) << std::endl;
	}
}
//================================================INPUT================================================//
void Engine::processInput(const float dt)
{
	mapUpdate();

	//Reads window events
	sf::Event event;
	while (window_.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window_.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				window_.close();
			break;

		default:
			break;
		}
	}
}
//================================================UPDATE================================================//
void Engine::update(const float dt)
{
	updateLevel();
	updateDM(dt);
}
//================================================RENDER================================================//
void Engine::renderFrame()
{
	window_.clear(sf::Color::Black);
	window_.setView(playerView_);

	
	int count = 0;
	//Draws all of the game objects
	for (std::list<Entity*>::reverse_iterator it = gameObjects_.rbegin();
	it != gameObjects_.rend(); it++)
	{
		window_.draw((*it)->sprite_);
		count++;
	}

	//std::cout << "object count: " << count << std::endl;
	
	window_.display();
}

//================================================PLAYER================================================//
void Engine::playerInput()
{
	//Resets where the palyer should be
	player1.currentPos = player1.sprite_.getPosition();
	player1.nextPos = player1.currentPos;

	//ORDER MATTERS, dont want player moivng and then checking door.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		sf::FloatRect rect(player1.getBoundingBox());

		switch (player1.facing)
		{
		case NORTH:
			rect.top -= TILESIZE_i;
			break;
		case SOUTH:
			rect.top += TILESIZE_i;
			break;
		case EAST:
			rect.left += TILESIZE_i;
			break;
		case WEST:
			rect.left -= TILESIZE_i;
			break;
		}

		if (useObject(rect))
		{
			lastPress_ = 0;
			//std::cout << "Used an Object!" << std::endl;
		}
		else
		{
			//std::cout << "Did not use an Object!" << std::endl;
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player1.nextPos.y -= TILESIZE_i;
		player1.sprite_.setTextureRect(sf::IntRect(TILESIZE_i, 3 * TILESIZE_i, TILESIZE_i, TILESIZE_i));
		player1.facing = NORTH;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player1.nextPos.y += TILESIZE_i;
		player1.sprite_.setTextureRect(sf::IntRect(TILESIZE_i, 0 * TILESIZE_i, TILESIZE_i, TILESIZE_i));
		player1.facing = SOUTH;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player1.nextPos.x -= TILESIZE_i;
		player1.sprite_.setTextureRect(sf::IntRect(TILESIZE_i, 1 * TILESIZE_i, TILESIZE_i, TILESIZE_i));
		player1.facing = WEST;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player1.nextPos.x += TILESIZE_i;
		player1.sprite_.setTextureRect(sf::IntRect(TILESIZE_i, 2 * TILESIZE_i, TILESIZE_i, TILESIZE_i));
		player1.facing = EAST;
	}
}

void Engine::updatePlayer(const float dt)
{
	//lastPress_ += dt;

	//if (lastPress_ >= PRESSTIME)
	//{
	//	playerInput();

	//	player1.sprite_.setPosition(player1.nextPos);
	//	sf::FloatRect rect = player1.sprite_.getGlobalBounds();

	//	if (!collisionCheck(rect))
	//	{
	//		//std::cout << "NO COLLISION" << std::endl;
	//		lastPress_ = 0;
	//	}
	//	else
	//	{
	//		//std::cout << "COLLISION!!!" << std::endl;
	//		player1.sprite_.setPosition(player1.currentPos);
	//		//lastPress_ = 0;
	//	}
	//}

	//playerView_.setCenter(player1.sprite_.getPosition());
}


void  Engine::mapUpdate()
{
	int x = player1.getLocation().x;
	int y = player1.getLocation().y;
	int w = currentRoom_->getWidth();
	int h = currentRoom_->getHeight();
	//std::cout << "Dungeon Pos: " << dungeon.getGlobalPos().x << ", " << dungeon.getGlobalPos().y;

	//std::cout << " Player Pos: " << x << ", " << y;

	std::string mess = " ";
	//if there is a northern door
	if (currentRoom_->getDoorN())
	{
		//if the player position is in that door
		int doorX = (currentRoom_->getX()*MRS_i);
		int doorY = -(currentRoom_->getY()*MRS_i + h / 2);

		//std::cout << " N: " << doorX << ", " << doorY;
		if (x == doorX && y == doorY)
		{
			dungeon.movePlayer(NORTH);
			mess = " NORTH ";
		}
	}
	if (currentRoom_->getDoorS())
	{
		//if the player position is in that door
		int doorX = (currentRoom_->getX()*MRS_i);
		int doorY = (-currentRoom_->getY()*MRS_i + h / 2);

		//std::cout << " S: " << doorX << ", " << doorY;
		if (x == doorX && y == doorY)
		{
			dungeon.movePlayer(SOUTH);
			mess = " South ";
		}
	}
	if (currentRoom_->getDoorE())
	{
		//if the player position is in that door
		int doorX = (currentRoom_->getX()*MRS_i + w / 2);
		int doorY = -(currentRoom_->getY()*MRS_i);

		//std::cout << " E: " << doorX << ", " << doorY;
		if (x == doorX && y == doorY)
		{
			dungeon.movePlayer(EAST);
			mess = " EAST ";
		}
	}
	if (currentRoom_->getDoorW())
	{
		//if the player position is in that door
		int doorX = (currentRoom_->getX()*MRS_i - w / 2);
		int doorY = -(currentRoom_->getY()*MRS_i);

		//std::cout << " E: " << doorX << ", " << doorY;
		if (x == doorX && y == doorY)
		{
			dungeon.movePlayer(WEST);
			mess = " WEST ";
		}
	}
	//std::cout << mess << std::endl;
}

//================================================LOADING================================================//

void Engine::loadTextures()
{
	texMan.loadTexture("tiles", "media/map_tile.png");
	texMan.loadTexture("character", "media/Actor2.png");

	tileTexture_ = texMan.getRef("tiles");
	playerText_ = texMan.getRef("character");
}

void Engine::loadLevel()
{
	currentRoomVect_ = currentRoom_->getRoomData();
}


//================================================COLLISION================================================//
bool Engine::useObject(sf::FloatRect rect)
{
	//Run through all the game objects for collision
	for (std::list<Entity*>::iterator it = gameObjects_.begin();
	it != gameObjects_.end(); ++it)
	{
		if (it != gameObjects_.begin())
		{
			if ((*it)->sprite_.getGlobalBounds().intersects(rect))
			{
				if ((*it)->canUse())
				{
					(*it)->use();
					//Collision found, test is true
					return true;
				}
			}
		}
	}
	return false;
}

bool Engine::collisionCheck(sf::FloatRect rect, std::size_t id)
{
	for (std::list<Entity*>::iterator it = gameObjects_.begin();
	it != gameObjects_.end(); ++it)
	{
		//Skips the player, should check the idenity vs game object
		if ((*it)->getID() != id)
		{
			if ((*it)->sprite_.getGlobalBounds().intersects(rect))
			{
				currentRoom_ = dungeon.currentRoomData();
				
				if ((*it)->isSolid()) 
				{
					//Collision found, test is true
					return true;
				}
			}
		}
	}
	//Check failed, no collision
	return false;
}
