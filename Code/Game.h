#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
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

	sf::Font font;
	sf::Text gameOverText;
	sf::Text finalScoreText;

	sf::SoundBuffer bufferGame;
	sf::Sound gameSound;
	sf::SoundBuffer bufferLoose;
	sf::Sound looseGameSoud;
	bool playEndGameSound;
	
	std::map<std::string, sf::Sprite> spritesMap;
	float dx;
	bool rotate;

	float startDelay = 1.f;
	float delay;

	void initWindow();
	void initVariables();
public:
	Game();
	~Game();

	void run();
	void pollEvent();
	bool endGame();

	void spawnNewTetromino();
	void fillMatrix(std::array<sf::Sprite,4> curTetr);
	void checkLines();

	void update();
	void renderElementOfMatrix(sf::RenderTarget* target);
	void renderEndGame();
	void render();
};

