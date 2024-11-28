#pragma once
#include<SFML/Graphics.hpp>
#include"Tetromino.h"
class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	Tetromino* tetromino;

	void initWindow();
	void initVariables();
public:
	Game();
	~Game();

	void run();
	void pollEvent();

	void update();
	void render();
};

