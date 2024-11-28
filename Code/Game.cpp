#include "Game.h"

//Private functions
void Game::initWindow()
{
	this->videoMode.height = 800.f;
	this->videoMode.width = 1000.f;

	this->window = new sf::RenderWindow(videoMode, "Tetris", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initVariables()
{
	this->tetromino = new Tetromino();
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
	}
}

void Game::update()
{
}

void Game::render()
{
	this->window->clear();

	//Draw some stuff
	this->window->draw(*tetromino);

	this->window->display();
}
