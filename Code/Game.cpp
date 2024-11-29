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
	this->rotate = false;
	this->timer = 0.f;
	this->delay = START_DELAY;

	if (!this->font.loadFromFile("Resourses/Napoli.ttf"))
		std::cerr << "Cannot load a font";

	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(100);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("GAME OVER");
	this->gameOverText.setPosition(250,250);

	this->finalScoreText.setFont(this->font);
	this->finalScoreText.setCharacterSize(50);
	this->finalScoreText.setFillColor(sf::Color::White);
	std::stringstream ss;
	ss << "Final score: " << this->stats.score;
	this->finalScoreText.setString(ss.str());
	this->finalScoreText.setPosition(350, 400);
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
		if (!endGame()) {
			this->time = clock.getElapsedTime().asSeconds();
			clock.restart();
			timer += time;

			this->update();

			this->render();
		}
		else {
			this->window->clear();
			this->window->draw(this->gameOverText);
			this->window->draw(this->finalScoreText);
			this->window->display();
		}
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
			else if (e.key.code == sf::Keyboard::Up) rotate = true;
			else if (e.key.code == sf::Keyboard::Down) delay = 0.05f;
		}
	}
}

bool Game::endGame()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->tetromino->getCurrTetr()[i].getGlobalBounds().top <= START_Y &&
			!this->tetromino->canFall()) return true;
	}
	return false;
}

void Game::spawnNewTetromino()
{
	this->tetromino = new Tetromino();
}

void Game::fillMatrix(std::array<sf::Sprite, 4> curTetr)
{
	for (int i = 0; i < 4; i++)
	{
		int x = static_cast<int>((curTetr[i].getPosition().x - START_X) / CELL_SIZE);
		int y = static_cast<int>((curTetr[i].getPosition().y - START_Y) / CELL_SIZE);
		matrix[x][y] = 1;

		//Create key
		std::stringstream ss;
		ss << x << " " << y;
		this->spritesMap[ss.str()] = curTetr[i];
	}
}

void Game::checkLines()
{
	bool deleteLine = true;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (matrix[j][i] == 0) {
				deleteLine = false;
				continue;
			}
		}
		if (deleteLine) {
			//Change matrix
			//Add score
			this->stats.score += 10;
			//Delete line
			for (int j = 0; j < COLUMNS; j++) {
				matrix[j][i] = 0;
				std::stringstream ss;
				ss << j << " " << i;
				this->spritesMap.erase(ss.str());
			}
			//Drop all cubes
			for (int k = i; k > 0; k--)
				for (int j = 0; j < COLUMNS; j++) {
					matrix[j][k] = matrix[j][k - 1];
					if (matrix[j][k - 1] == 1) {
						std::stringstream oldKey;
						oldKey << j << " " << k - 1;						
						std::stringstream newKey;
						newKey << j << " " << k;
						this->spritesMap[newKey.str()] = this->spritesMap[oldKey.str()];
						this->spritesMap.erase(oldKey.str());
						this->spritesMap[newKey.str()].setPosition(
							spritesMap[newKey.str()].getPosition().x,
							spritesMap[newKey.str()].getPosition().y + 1.f * CELL_SIZE);
					}
				}
		}
		deleteLine = true;
	}
}

void Game::update()
{
	if (this->tetromino->canFall()) {
		if (timer > this->delay) {
			this->tetromino->fall();
			this->timer = 0.f;
			this->delay = START_DELAY;
		}
		else if (rotate) {
			this->tetromino->rotate();
			this->rotate = false;
		}
		if (dx != 0) {
			this->tetromino->updateX(this->dx);
			this->dx = 0;
		}
	}
	else {
		this->fillMatrix(this->tetromino->getCurrTetr());
		this->checkLines();
		this->spawnNewTetromino();
	}
	this->stats.update();
}

void Game::renderElementOfMatrix(sf::RenderTarget* target)
{
	for (const auto& vl : this->spritesMap)
		target->draw(vl.second);
}

void Game::render()
{
	this->window->clear();

	//Draw some stuff
	this->stats.render(this->window);
	this->tetromino->renderFigure(this->window);
	this->renderElementOfMatrix(this->window);
	this->window->draw(board);

	this->window->display();
}
