#pragma once

#include<SFML/Graphics.hpp>

#include<random>
#include<array>

#include "Const.h"


class Tetromino
{
private:
	int typeOfFigure;

	//Cube sprite
	sf::Texture cubeTexture;
	sf::Sprite currentBlock[4];

	int color;

	sf::Clock clock;
	float timer;

	static const int FIGURES[7][4];

	//Coordinate of 4 cubes that make figure
	struct Points { int x, y; } figure[4];

	void initVariables();
	void initSprites();

public:
	Tetromino();

	void createFigure();
	void updateX(float dx);
	void fall();
	bool checkBounds(float dx);
	bool canFall();
	void renderFigure(sf::RenderTarget* target);

	std::array<sf::Sprite, 4> getCurrTetr();
	const int getRundomNum(int start, int end) const;
};

