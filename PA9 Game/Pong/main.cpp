#include "Game.h"
//http://xoxlabs.com/x/unity/2D_Mario_Clone/2D%20Mario%20Clone/Assets/2D%20Mario%20Assets/Textures/
//fixing linker error, change in linker-input-additional dependencies change all the sfml-graphics.lib
//to sfml-graphics-d.lib for all the dependencies

int main()
{
	srand((unsigned int)time(NULL));
	Game game = *(new Game());
}