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
	this->setPosition(250, 500);
	//this->Frames[0][0] = sf::IntRect({ 0, 0, 256, 292.6 });
	this->velocityX = 0;
	this->velocityY = 0;
	this->accelerationX = 0;
	this->accelerationY = 0;
}

Mario::~Mario()
{

}

void Mario::Animate(int frame)
{
	static int index1 = 0;
	if (frame != 10 && frame != 11)
	{
		index1 = 0;
		static int index = 0;
		this->setTextureRect(this->Frames[frame][index]);
		if (index != 15)
			++index;
		else
			index = 0;
	}
	else
	{
		static int index1 = 0;
		this->setTextureRect(this->Frames[frame][index1]);
		if (index1 != 15)
			++index1;
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

float Mario::getAccelerationY(void)
{
	return this->accelerationY;
}
void Mario::setAccelerationY(float newAccelerationY)
{
	this->accelerationY = newAccelerationY;
}

void Mario::adjustVelocity(void)
{
	this->velocityY += this->accelerationY;
}

void Mario::setAccelerationX(float newAccelerationX) { accelerationX = newAccelerationX; }

float Mario::getAccelerationX() { return accelerationX; }