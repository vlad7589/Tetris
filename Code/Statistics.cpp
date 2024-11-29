#include "Statistics.h"

void Statistics::initVariables()
{
	this->score = 0;

	if (!this->font.loadFromFile("Resourses/Napoli.ttf"))
		std::cerr << "Cannot load a font";
	
	this->scoreText.setFont(this->font);
	this->scoreText.setCharacterSize(48);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setString("TEST");
	this->scoreText.setPosition(START_TEXT_POS_X, START_TEXT_POS_Y);

	this->tutorialText.setFont(this->font);
	this->tutorialText.setCharacterSize(24);
	this->tutorialText.setFillColor(sf::Color::Green);
	this->tutorialText.setString("USE LEFT AND RIGHT TO MOVE BY X\n\nPRESS UP TO ROTATE TETRAMINO\n\nPRESS DOWN TO MAKE FALLING FASTER");
	this->tutorialText.setPosition(START_TEXT_POS_X, START_TEXT_POS_Y + this->scoreText.getCharacterSize()*2);
}		  

Statistics::Statistics()
{
	this->initVariables();
}

void Statistics::update()
{
	std::stringstream ss;
	ss << "SROCE: " << this->score << "\n";
	this->scoreText.setString(ss.str());
}

void Statistics::render(sf::RenderTarget* targer)
{
	targer->draw(this->scoreText);
	targer->draw(this->tutorialText);
}
