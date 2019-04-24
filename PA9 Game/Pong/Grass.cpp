#include "Grass.h"

Grass::Grass(const sf::Texture &texture) : Sprite(texture)
{
	//this->setTextureRect({ 0,500,500,500 });
	this->setPosition(0, 744);
}

Grass::~Grass()
{

}