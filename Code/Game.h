#pragma once
#include<SFML/Graphics.hpp>
#include"Tetromino.h"
#include"Board.h"
#include"Const.h"
#include"Statistics.h"

#include<array>
#include<map>
#include<string>
#include<sstream>
class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	Tetromino* tetromino;
	Board board;

	Statistics stats;

	sf::Clock clock;
	float time;
	float timer;

	//Matric of cubes
	
	std::map<std::string, sf::Sprite> spritesMap;
	float dx;
	bool rotate;

	float delay;

	void initWindow();
	void initVariables();
public:
	Game();
	~Game();

	void run();
	void pollEvent();

	void spawnNewTetromino();
	void fillMatrix(std::array<sf::Sprite,4> curTetr);
	void checkLines();

	void update();
	void renderElementOfMatrix(sf::RenderTarget* target);
	void render();
};

