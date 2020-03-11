#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <stdlib.h>
#include "constants.h"
#include "Snake.h"
#include "Grid.h"
#include "Fruit.h"
#include "InfoDisplay.h"
#include <string>

using namespace constants;

int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT+100), "Snake");

	Snake snake(90, 90);
	Grid grid(WIDTH/CW, HEIGHT/CH);
    	Fruit fruit;

    	sf::Font font;
    	font.loadFromFile("fonts/OpenSans-Regular.ttf");

    	std::vector<sf::Sprite> hearts;

    	sf::Text scoreText("Score: ", font);
    	scoreText.setCharacterSize(TEXT_SIZE);
    	scoreText.setFillColor(TEXT_COLOR);
    	scoreText.setPosition(40, 630);

    	sf::Texture texture;
    	texture.loadFromFile("imgs/heart.png");

	for(int i = 0; i < LIFE; i++) {
        	sf::Sprite sprite;
        	sprite.setTexture(texture);
        	sprite.setPosition(450+34*i, 630);
        	sprite.setScale(0.04,0.04);
        	hearts.push_back(sprite);
    	}

    	//std::cout << snake.getLifeCount() << std::endl;
	while(window.isOpen()) {
		sf::Event event;

        	while (window.pollEvent(event)) {
        		if (event.type == sf::Event::Closed) {
                		window.close();
            		}
            		if(event.type == sf::Event::EventType::KeyPressed) {
            			switch(event.key.code) {
            				case sf::Keyboard::Right: {
            					if(snake.getDirection() != LEFT) snake.setDirection(RIGHT);
            					break;
            				}
            				case sf::Keyboard::Left: {
            					if(snake.getDirection() != RIGHT) snake.setDirection(LEFT);
            					break;
            				}
            				case sf::Keyboard::Up: {
            					if(snake.getDirection() != DOWN) snake.setDirection(UP);
            					break;
            				}
            				case sf::Keyboard::Down: {
            					if(snake.getDirection() != UP) snake.setDirection(DOWN);
            					break;
            				}
            			}
            		}
        	}

        	window.clear();
        	/* DRAW GRID */
        	for(int i = 0; i < (WIDTH*HEIGHT)/(CW*CH); i++) {
        		window.draw(grid.grid_cells[i]);
        	}
        	/* DRAW SNAKE */
        	for(int i = 0; i < snake.getSize(); i++) {
        		window.draw(snake.snake_cells[i]);
       		}
        	/* DRAW FRUIT */
        	window.draw(fruit.fruit);
        	/* DRAW TEXT ADN HEARTS */
        	std::string s = "Score: ";
        	s += std::to_string(snake.getScore());
        	scoreText.setString(s);
        	window.draw(scoreText);
        	for(int i = 0; i < hearts.size(); i++) {
        	    window.draw(hearts[i]);
        	}
        	/* MOVE SNAKE */
        	switch(snake.getDirection()) {
        		case RIGHT: snake.move(CW,0); break;
        		case LEFT: snake.move(-1*CW,0); break;
        		case UP: snake.move(0,-1*CH); break;
        		case DOWN: snake.move(0,CH); break;
        	}
        	/* CHECK COLLISIONS */
        	if(snake.collides(fruit.getX(), fruit.getY())) {
         		snake.addCell();
         		fruit.setRandomLocation(snake);
          		snake.addScore(10);
        	}
        	if(snake.getX() >= WIDTH) snake.setLocation(0, snake.getY());
        	if(snake.getX() < 0) snake.setLocation(WIDTH-CW, snake.getY());
        	if(snake.getY() >= HEIGHT) snake.setLocation(snake.getX(), 0);
        	if(snake.getY() < 0) snake.setLocation(snake.getX(), HEIGHT-CH);

        	if(snake.collidesItself()) {
            		snake.reset(90,90);
           		hearts.pop_back();
            		//std::cout << snake.getLifeCount() << std::endl;
        	}

        	if(snake.getLifeCount() == 0) {
           		break;
        	}
        	sf::sleep(sf::seconds(0.06));
        	window.display();
	}
	return 0;
}
