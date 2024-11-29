#include "Tetromino.h"
#include<iostream>
//Here used a table 2x4 with number from 0 to 7
//When you need some figures you pick only number that covers your figure
// 0 1
// 2 3
// 4 5 
// 6 7
const int Tetromino::FIGURES[7][4] = {
	1,3,5,7,	// I
	2,3,4,5,	// O
	2,4,5,7,	// S
	3,5,4,6,	// Z
	0,3,4,5,	// L
	1,3,4,5,	// J
	1,2,3,5,	// T
};

//Private function
void Tetromino::initVariables()
{

	this->color = this->getRundomNum(0,8);
	this->typeOfFigure = *this->FIGURES[this->getRundomNum(0,7)];
	
	for (int i = 0; i < 4; i++)
	{
		this->currentBlock[i].setTextureRect(sf::IntRect(color * 18, 0, 18, 18));
		this->currentBlock[i].setScale(
			CELL_SIZE / 18,
			CELL_SIZE / 18
		);
		this->currentBlock[i].setPosition(START_X, START_Y);
	}
}

void Tetromino::initSprites()
{
	
	if (!this->cubeTexture.loadFromFile("Resourses/tiles.png"))
		std::cout << "Cannot load a texture tiles";

	for (int i = 0; i < 4; i++)
	{
		this->currentBlock[i].setTexture(cubeTexture);
	}
}

//Constructor
Tetromino::Tetromino()
{
	this->initSprites();
	this->initVariables();
	this->createFigure();
}

//Functions
void Tetromino::createFigure()
{

	for (int i = 0; i < 4; i++)
	{
		//For example let take a I(1,3,5,7), cause of every number consecutive odd x every type will be 1
		//But for every next y we will add 1 and cubes will "go down"
		this->figure[i].x = FIGURES[this->typeOfFigure][i] % 2;
		this->figure[i].y = FIGURES[this->typeOfFigure][i] / 2;

		currentBlock[i].setPosition(
			this->figure[i].x * CELL_SIZE + this->currentBlock[i].getGlobalBounds().left, 
			this->figure[i].y * CELL_SIZE + this->currentBlock[i].getGlobalBounds().top);
	}
}

void Tetromino::updateX(float dx)
{
	if (!checkBounds(dx)) {
		for (int i = 0; i < 4; i++)
		{
			this->currentBlock[i].setPosition(
				this->currentBlock[i].getPosition().x + dx * CELL_SIZE,
				this->currentBlock[i].getPosition().y);
		}
	}

}

void Tetromino::fall()
{
	if (canFall()) {
		for (int i = 0; i < 4; i++)
		{
			this->currentBlock[i].setPosition(
				this->currentBlock[i].getPosition().x,
				this->currentBlock[i].getPosition().y + 1.f * CELL_SIZE);
		}
	}
}

bool Tetromino::checkBounds(float dx)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->currentBlock[i].getGlobalBounds().left + dx * CELL_SIZE < START_X ||
			this->currentBlock[i].getGlobalBounds().left + dx * CELL_SIZE >(COLUMNS + 1) * CELL_SIZE) return true;
	}
	return false;
}

bool Tetromino::canFall()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->currentBlock[i].getGlobalBounds().top + CELL_SIZE > (ROWS + 1) * CELL_SIZE) return false;
	}
	return true;
}

void Tetromino::renderFigure(sf::RenderTarget* target)
{
	for (int i = 0; i < 4; i++)
	{
		target->draw(currentBlock[i]);
	}
}

const int Tetromino::getRundomNum(int start, int end) const
{
	return start + (int)(end * (rand()/(RAND_MAX + 1.0)));
}

