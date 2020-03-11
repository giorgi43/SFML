#include <SFML/Graphics.hpp>
#include <vector>
#include "Grid.h"
#include "constants.h"

using namespace constants;

Grid::Grid(int w, int h) {
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			sf::RectangleShape cell(sf::Vector2f(CW, CH));
			cell.setFillColor(sf::Color::Black);
			cell.setOutlineColor(GRID_LINE_COLOR);
			cell.setOutlineThickness(1);
			cell.setPosition(j*CW, i*CH);
			grid_cells.push_back(cell);
		}
	}
}
