#include "Mario.h"

Mario::Mario(const sf::Texture &texture) : Sprite(texture)
{
	//set each frame 4096X4096 //position, size
	float x, y;
	int index1 = 0, index2 = 0;
	for (; index1 < 14; index1++) // columns
	{
		for (index2 = 0; index2 < 16; index2++) // rows
		{
			this->Frames[index1][index2] = sf::IntRect({ index2 * 256, index1 * 256, 256, 256 });
		}
	}
	this->setTextureRect({ 0,0,256,293 });
	this->setPosition(500, 500);
	//this->Frames[0][0] = sf::IntRect({ 0, 0, 256, 292.6 });

}

Mario::~Mario()
{

}

void Mario::Animate(int frame)
{
	if (frame != 10)
	{
		static int index = 0;
		this->setTextureRect(this->Frames[frame][index]);
		if (index != 15)
			++index;
		else
			index = 0;
	}
	else
	{
		static int index = 0;

	}
}

float Mario::getVelocityX(void)
{
	return this->velocityX;
}
float Mario::getVelocityY(void)
{
	return this->velocityY;
}

void Mario::setVelocityX(float newVelocityX)
{
	this->velocityX = newVelocityX;
}
void Mario::setVelocityY(float newVelocityY)
{
	this->velocityY = newVelocityY;
}