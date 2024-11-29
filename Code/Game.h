#pragma once
#include<SFML/Graphics.hpp>
#include"Tetromino.h"
#include"Board.h"
#include"Const.h"

#include<array>
#include<vector>
class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	Tetromino* tetromino;
	Board board;

	sf::Clock clock;
	float time;
	float timer;

	//Matric of cubes
	
	std::vector<sf::Sprite> spritesArr;
	float dx;

	void initWindow();
	void initVariables();
public:
	Game();
	~Game();

	void run();
	void pollEvent();

	void spawnNewTetromino();
	void fillMatrix(std::array<sf::Sprite,4> curTetr);

	void update();
	void renderElementOfMatrix(sf::RenderTarget* target);
	void render();
};

