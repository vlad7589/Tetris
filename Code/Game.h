#pragma once
#include<SFML/Graphics.hpp>
#include"Tetromino.h"
#include"Board.h"
#include"Const.h"
class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	Tetromino* tetromino;
	Board board;

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

