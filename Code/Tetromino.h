#pragma once

#include<SFML/Graphics.hpp>
#include<random>
#include<iostream>

#include "Const.h"

class Tetromino : public sf::Drawable, public sf::Transformable
{
private:
	int typeOfFigure;

	//Cube sprite
	sf::Texture cubeTexture;
	sf::Sprite currentBlock[4];

	int color;

	static const int FIGURES[7][4];

	//Coordinate of 4 cubes that make figure
	struct Points { int x, y; } figure[4];

	void initVariables();
	void initSprites();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
	Tetromino();

	void createFigure();

	const int getRundomNum(int start, int end) const;
};

