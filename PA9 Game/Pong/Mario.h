#pragma once
#include <SFML/Graphics.hpp>

//14 by 16 frames
class Mario : public sf::Sprite {
public:
	Mario(const sf::Texture &texture);
	~Mario();
	void Animate(int frame);
	float getVelocityX(void);
	float getVelocityY(void);
	void setVelocityX(float newVelocityX);
	void setVelocityY(float newVelocityY);
private:
	sf::IntRect Frames[14][16];
	float velocityX;
	float velocityY;
	float accelerationX;
	float accelerationY;
};