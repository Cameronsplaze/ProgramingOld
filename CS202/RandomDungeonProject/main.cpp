#include <SFML/Graphics.hpp>
#include <iostream>

#include "Engine.hpp"

int main()
{
	Engine engine;

	try
	{
		engine.go();
	}
	catch (char* e)
	{
		std::cerr << "Failed to load Engine. /nMessage: " << e << std::endl;
	}

	return 0;
}
