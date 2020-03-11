#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Grid {
	public:
		std::vector<sf::RectangleShape> grid_cells;
		Grid(int, int);
};
