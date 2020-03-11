#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"
#include <stdlib.h>
#include <time.h>
#include "Snake.h"

using namespace constants;

class Fruit {
		int x, y;
		int randX();
		int randY();
	public:
		sf::RectangleShape fruit;
		Fruit();
		void setRandomLocation(Snake snake);
		int getX();
		int getY();

};
