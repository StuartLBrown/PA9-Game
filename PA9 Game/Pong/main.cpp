#include "Game.h"

//fixing linker error, change in linker-input-additional dependencies change all the sfml-graphics.lib
//to sfml-graphics-d.lib for all the dependencies

int main()
{
	srand((unsigned int)time(NULL));
	Game game = *(new Game());

	return 0;
}