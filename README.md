# SFML
games and other stuff made with SFML

## snake
compile:
```
g++ -c game.cpp Snake.cpp Grid.cpp Fruit.cpp
g++ -o snake game.o Snake.o Grid.o Fruit.o -lsfml-graphics -lsfml-window -lsfml-system
```
run:
```
./snake
```
