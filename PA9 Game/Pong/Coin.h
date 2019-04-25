#include "SFML\Graphics.hpp"
#include <iostream>

using std::cout;
using std::endl;


class Coin :
	public sf::Sprite
{
public:
	Coin(const sf::Texture &texture2);
	~Coin();

	void newCoin();

private:
	int coinNum; //max 8
};
