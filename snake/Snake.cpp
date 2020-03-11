#include "Snake.h"
#include <SFML/Graphics.hpp>
#include "constants.h"

using namespace constants;

Snake::Snake(int a, int b) {
	x = a;
	y = b;
	size = DEFAULT_SNAKE_SIZE;
	direction = NONE;
	life_left = LIFE;
	score = 0;
	for(int i = 0; i < size; i++) {
		sf::RectangleShape cell(sf::Vector2f(CW, CH));
		cell.setFillColor(SNAKE_COLOR);
		cell.setPosition(x - i*CW, y);
		snake_cells.push_back(cell);
	}
}

int Snake::getX() {
	return x;
}

int Snake::getY() {
	return y;
}

void Snake::reset(int a, int b) {
	//life_left = LIFE;
	size = DEFAULT_SNAKE_SIZE;
	direction = NONE;
	snake_cells.clear();
	x = a;
	y = b;
	for(int i = 0; i < size; i++) {
		sf::RectangleShape cell(sf::Vector2f(CW, CH));
		cell.setFillColor(SNAKE_COLOR);
		cell.setPosition(x - i*CW, y);
		snake_cells.push_back(cell);
	}
}

void Snake::addCell() {
	sf::RectangleShape cell(sf::Vector2f(CW, CH));
	cell.setFillColor(SNAKE_COLOR);
	int last_x = snake_cells[size-1].getPosition().x;
	int last_y = snake_cells[size-1].getPosition().y;
	cell.setPosition(last_x - CW, last_y);
	snake_cells.push_back(cell);
	size++;
}

int Snake::getSize() {
	return size;
}

void Snake::move(int dx, int dy) {
	sf::Vector2f lastPosition(snake_cells[0].getPosition().x, snake_cells[0].getPosition().y);
	snake_cells[0].move(dx, dy);
	// update x and y
	x += dx;
	y += dy;
	for(int i = 1; i < size; i++) {
		sf::Vector2f lastTemp(snake_cells[i].getPosition().x, snake_cells[i].getPosition().y);
		snake_cells[i].setPosition(lastPosition.x, lastPosition.y);
		lastPosition.x = lastTemp.x;
		lastPosition.y = lastTemp.y;
	}
}

int Snake::getDirection() {
	return direction;
}

void Snake::setDirection(int d) {
	direction = d;
}

bool Snake::collides(int fx, int fy) {
	if(x == fx && y == fy) return true;
	return false;
}

bool Snake::collidesItself() {
	for(int i = 1; i < size; i++) {
		if(snake_cells[i].getPosition().x == x && snake_cells[i].getPosition().y == y) {
			life_left--;
			return true;
		}
	}
	return false;
}

void Snake::setLocation(int a, int b) {
	x = a;
	y = b;
	snake_cells[0].setPosition(x,y);
}

int Snake::getLifeCount() {
	return life_left;
}

void Snake::addScore(int s) {
	score += s;
}

int Snake::getScore() {
	return score;
}

void Snake::setSnakeColor(sf::Color c) {
	for(int i = 0; i < size; i++) {
		snake_cells[i].setFillColor(c);
	}
}
