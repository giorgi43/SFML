#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Snake {
	private:
		int x, y, size, life_left, direction, score;
	public:
		std::vector<sf::RectangleShape> snake_cells;
		Snake(int, int);
		int getX(); // get x of head
		int getY(); // get y of head
		int getSize(); // get number of snake cells
		void reset(int, int); // reset snake to defaults. @params - (x,y) coords for spawn
		void addCell(); // add one cell to snake
		void move(int, int); // move snake from current position @params - (dx, dy)
		int getDirection(); // get snake's direction
		void setDirection(int); // set snake's direction
		bool collides(int, int); // check if snake collides (x,y) point(fruit)
		bool collidesItself(); // check if snake collides itself
		void setLocation(int, int); // set new snake location
		int getLifeCount();
		void addScore(int);
		int getScore();
		void setSnakeColor(sf::Color c);
};
