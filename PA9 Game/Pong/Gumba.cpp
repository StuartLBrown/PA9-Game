#include "Gumba.h"

Gumba::Gumba(const sf::Texture &texture) : Sprite(texture)
{
	int index1 = 0, index2 = 0;
	for (; index1 < 12; index1++) // columns
	{
		for (index2 = 0; index2 < 16; index2++) // rows
		{
			this->Frames[index1][index2] = sf::IntRect({ index2 * 256, index1 * 256, 256, 256 });
		}
	}
	this->setPosition(500, 500);
	this->velocityX = 1;
	this->velocityY = 0;
	this->setTextureRect({ 0,0,256,293 });
}
Gumba::~Gumba()
{

}
void Gumba::Animate(int frame)
{
	static int index = 0;
	this->setTextureRect(this->Frames[frame][index]);
	if (index != 15)
		++index;
	else
		index = 0;
}

float Gumba::getVelocityX(void)
{
	return this->velocityX;
}
float Gumba::getVelocityY(void)
{
	return this->velocityY;
}

void Gumba::setVelocityX(float newVelocityX)
{
	this->velocityX = newVelocityX;
}
void Gumba::setVelocityY(float newVelocityY)
{
	this->velocityY = newVelocityY;
}

bool Gumba::isHit(void)
{
	return false;
}
