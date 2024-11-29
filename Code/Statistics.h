#pragma once
#include<SFML/Graphics.hpp>
#include<sstream>
#include<iostream>
#include"Const.h"
class Statistics
{
private:

	sf::Font font;
	sf::Text scoreText;
	sf::Text tutorialText;

	void initVariables();
public:
	int score;

	Statistics();

	void update();
	void render(sf::RenderTarget* targer);
};

