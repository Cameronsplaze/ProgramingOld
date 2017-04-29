/*
Alex Medeiros
Texture Manager:
	Loads Assests andd keeps track of them for Engine.
*/
#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager
{
public:
	TextureManager() {}

	//Adds Texture from file
	void loadTexture(const std::string& name, const std::string& fileName);

	//Translates ID to reffernce
	//Tells us where a texture is
	sf::Texture& getRef(const std::string& texture);

private:
	//Array used for holding textures
	std::map<std::string, sf::Texture> textures_;

};

