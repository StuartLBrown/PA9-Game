//http://xoxlabs.com/x/unity/2D_Mario_Clone/2D%20Mario%20Clone/Assets/2D%20Mario%20Assets/Textures/
// This example will use SFML libraries to implement
// the game of Pong

// History: 4/12 - Designed a Paddle class. Have yet to 
//                 instantiate one of these.
//          4/10 - Designed and implemented a Ball class that's
//                 derived from a sf::CircleShape.
//          4/8 - Started from the SFML tutorial code that draws
//                a circle in the window.
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include "testmain.h"
#include "Mario.h"
#include "Gumba.h"

int main()
{
	//testmario();
	testGumba();
	return 0;
}