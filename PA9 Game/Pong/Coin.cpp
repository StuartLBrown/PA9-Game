#include "Coin.h"



Coin::Coin(const sf::Texture &texture2) : Sprite (texture2)
{
	coinNum = 0;
	this->setScale(.15, .15);
	this->setPosition(750, 600);
	
}


Coin::~Coin()
{
}

void Coin::newCoin()
{
	//8 coins max
	coinNum++;
	switch (coinNum)
	{
	case 1: this->setPosition(1500, 600);
		cout << "Coins Collected : " << coinNum << endl;
		break;
	case 2: this->setPosition(1750, 600);
		cout << "Coins Collected : " << coinNum << endl;
		break;
	case 3: this->setPosition(2500, 600);
		cout << "Coins Collected : " << coinNum << endl;
		break;
	case 4: this->setPosition(2600, 600);
		cout << "Coins Collected : " << coinNum << endl;
		break;
	case 5: this->setPosition(2700, 600);
		cout << "Coins Collected : " << coinNum << endl;
		break;
	case 6: this->setPosition(3000, 600);
		cout << "Coins Collected : " << coinNum << endl;
		break;
	case 7: this->setPosition(3500, 600);
		cout << "Coins Collected : " << coinNum << endl;
		break;
	case 8: this->setPosition(0, 0);
		cout << "all coins collected!!!" << endl;

	}
}
