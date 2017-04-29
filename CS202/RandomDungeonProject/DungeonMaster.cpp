/*
Alex Medeiros
Dungeon Master
The job of dungeon master is to control all of the PC and NPC in a room.
If combat is not happeneing than movment will be free.
Dungeon master may set some amilities not useable because combat is not happening.
*/


#include "Event.hpp"
#include "Engine.hpp"
#include "Player.hpp"
#include "Attack.hpp"
#include "Dice.h"

void Engine::updateDM(const float dt)
{
	playerTurns(dt);
	playerView_ = player1.playerView;
}


void Engine::playerTurns(const float dt)
{
	
	for (std::list<Player*>::iterator it = players_.begin(); 
		it != players_.end(); it++)
	{
		if (!(*it)->isDead())
		{
			std::size_t id = (*it)->getID();
			removePlayer(id);
			players_.remove((*it));

			std::cout << "PLAYER REMOVED" << std::endl;
			break;
		}

		if ((*it)->turn())
		{
			//Reads the player Input
			sf::Vector2i loc;
			sf::FloatRect coll;
			sf::FloatRect obj;
			Event e(COLLISION, coll);
			e.add(USEOBJECT, obj);
			e.add(loc, false);

			Event ef(COLLISION, coll);
			ef.add(USEOBJECT, obj);


			(*it)->handleInput(e, dt);
			(*it)->getID();
			//Checks for collisions that the player has

			if (e.getState(ATTACK))
			{
				std::cout << "I Am Attacking!" << std::endl;
				attack((*it), e.getLocation());
			}
			if (collisionCheck(e.getRect(COLLISION), (*it)->getID()))
			{
				//std::cout << "collision Found in engine" << std::endl;
				e.setState(COLLISION, true);
			}	
			if (useObject(e.getRect(USEOBJECT)))
			{
				e.setState(USEOBJECT, true);
			}

			(*it)->update(e, dt);

			
			
		}

	}
}

void Engine::addPlayer(Player* play)
{
	//Adds the player to the Player Vectro
	players_.push_back(play);
	//Adds the player to the Game Objects
	gameObjects_.push_back(play);
	//Sets the Game object to a unique ID
	gameObjecCountID_++;
	play->setID(gameObjecCountID_);
}

void Engine::removePlayer(std::size_t id)
{
	for (std::list<Entity*>::iterator it = gameObjects_.begin();
		it != gameObjects_.end(); ++it)
	{
		if ((*it)->getID() == id)
		{
			gameObjects_.remove(*it);
			return;
		}
	}
}

bool Engine::attack(Player* attacker, sf::Vector2i loc)
{
	for (auto def : players_)
	{
		if (def->getLocation() == loc)
		{
			int attackRoll = attacker->baseAttack.attackRoll();
			int damage =  attacker->baseAttack.getDamage();

			//If the attack roll overcomes the Armor class of the defender
			if (def->getAC() <= attackRoll)
			{
				def->setDamage(damage);
				std::cout << "Defender Health = " << def->getHP() << std::endl;
				return true;
			}
		}
	}
	return false;
}