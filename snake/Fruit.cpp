#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Fruit.h"
#include <stdlib.h>
#include <time.h>
#include "Snake.h"

using namespace constants;

int Fruit::randX() {
	int xx = std::rand()%(WIDTH/CW);
	return CW*xx;
}

int Fruit::randY() {
	int yy = std::rand()%(HEIGHT/CH);
	return CH*yy;
}

Fruit::Fruit() {
	std::srand(time(NULL));
	x = randX();
	y = randY();
	fruit.setSize(sf::Vector2f(CW, CH));
	fruit.setPosition(x,y);
	fruit.setFillColor(FRUIT_COLOR);
}

void Fruit::setRandomLocation(Snake snake) {
	while(true) {
		x = randX();
		y = randY();
		bool temp = false;
		for(int i = 0; i < snake.getSize(); i++) {
			if(snake.snake_cells[i].getPosition().x == x && snake.snake_cells[i].getPosition().y == y) {
				temp = true;
			}
		}
		if(temp == false) break;
	}
	fruit.setPosition(x,y);
}

int Fruit::getX() {
	return x;
}

int Fruit::getY() {
	return y;
}

