#include "Game.h"
#include<iostream>
#include"Matrix.h"

//Private functions
void Game::initWindow()
{
	this->videoMode.height = WINDOW_HEIGHT;
	this->videoMode.width = WINDOW_WIDTH;

	this->window = new sf::RenderWindow(videoMode, "Tetris", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initVariables()
{
	this->tetromino = new Tetromino();
	this->dx = 0.f;
	this->timer = 0.f;
}

//Constructor / Destructor
Game::Game()
{
	this->initWindow();
	this->initVariables();
}

Game::~Game()
{
	delete this->window;
	delete this->tetromino;
}


//Functions
void Game::run()
{
	while (window->isOpen())
	{
		this->time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		//Check user input
		this->pollEvent();

		this->update();

		this->render();
	}
}

void Game::pollEvent()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			this->window->close();
		else if (e.type == sf::Event::KeyPressed) {
			if (e.key.code == sf::Keyboard::Left) dx = -1.f;
			else if (e.key.code == sf::Keyboard::Right) dx = 1.f;
		}
	}
}

void Game::spawnNewTetromino()
{
	this->tetromino = new Tetromino();
}

void Game::fillMatrix(std::array<sf::Sprite, 4> curTetr)
{
	for (int i = 0; i < 4; i++)
	{
		matrix[static_cast<int>((curTetr[i].getPosition().x - START_X) / CELL_SIZE )]
			[static_cast<int>((curTetr[i].getPosition().y - START_Y) / CELL_SIZE )] = 1;
		this->spritesArr.push_back(curTetr[i]);
	}
}

void Game::checkLines()
{
}

void Game::update()
{
	if (this->tetromino->canFall()) {
		if (timer > DELAY) {
			this->tetromino->fall();
			this->timer = 0.f;
		}
		if (dx != 0) {
			this->tetromino->updateX(this->dx);
			this->dx = 0;
		}
	}
	else {
		this->fillMatrix(this->tetromino->getCurrTetr());
		this->spawnNewTetromino();
	}
}

void Game::renderElementOfMatrix(sf::RenderTarget* target)
{
	for (int i = 0; i < this->spritesArr.size(); i++)
	{
		target->draw(this->spritesArr[i]);
	}
}

void Game::render()
{
	this->window->clear();

	//Draw some stuff
	this->tetromino->renderFigure(this->window);
	this->renderElementOfMatrix(this->window);
	this->window->draw(board);

	this->window->display();
}
