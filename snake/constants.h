/* Game constants */
#ifndef GAME_CONSTANTS
#define GAME_CONSTANTS
#include <SFML/Graphics.hpp>

namespace constants {
	/* WINDOW */
	const int WIDTH = 600;
	const int HEIGHT = 600;
	/* CELL WIDTH AND HEIGHT */
	const int CW = 30; 
	const int CH = 30;
	/* SNAKE */
	const sf::Color SNAKE_COLOR = sf::Color::Green;
	const sf::Color SNAKE_HEAD_COLOR = sf::Color::Yellow;//(255,86,25,255);
	const int DEFAULT_SNAKE_SIZE = 3;
	/* GRID */
	const sf::Color GRID_LINE_COLOR = sf::Color(220,220,220,20);
	//const sf::Color GRID_WALL_COLOR = sf::Color::Magenta;
	/* DIRECTIONS */
	const int RIGHT = 0;
	const int LEFT = 1;
	const int UP = 2;
	const int DOWN = 3;
	const int NONE = -1;
	/* */
	const int LIFE = 3;

	const sf::Color FRUIT_COLOR = sf::Color::Red;

	const int TEXT_SIZE = 25;

	const sf::Color TEXT_COLOR = sf::Color::White;

}

#endif 
