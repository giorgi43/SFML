# SFML
games and other stuff made with SFML

p.s code is terrible 

### install SFML first
on debian:
```
sudo apt install libsfml-dev
```
## snake
compile:
```
g++ -c game.cpp Snake.cpp Grid.cpp Fruit.cpp
g++ -o snake game.o Snake.o Grid.o Fruit.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
```
run:
```
./snake
```
