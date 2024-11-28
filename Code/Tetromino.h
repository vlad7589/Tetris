#pragma once

#include<SFML/Graphics.hpp>
#include<random>
#include<iostream>

class Tetromino : public sf::Drawable, public sf::Transformable
{
private:
	const float CELL_SIZE = 1.5f * 18; // * 18 'cause one cube from tiles.png have 18.f pizel size
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

