#include "TextureManager.hpp"

//Adds Texture from file
void TextureManager::loadTexture(const std::string& name, const std::string& fileName)
{
	sf::Texture tex;
	tex.loadFromFile(fileName);

	textures_[name] = tex;
}

//Translates ID to reffernce
//Tells us where a texture is
sf::Texture& TextureManager::getRef(const std::string& texture)
{
	return textures_.at(texture);
}