#pragma once
#include <SFML/Graphics.hpp>

class Gumba : public sf::Sprite {
public:
	Gumba(const sf::Texture &texture);
	~Gumba();
	void Animate(int frame);
	float getVelocityX(void);
	float getVelocityY(void);
	void setVelocityX(float newVelocityX);
	void setVelocityY(float newVelocityY);
	bool isHit(void);
private:
	sf::IntRect Frames[12][16];
	float velocityX;
	float velocityY;
};