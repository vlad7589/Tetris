#pragma once
#include<SFML/Graphics.hpp>

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	void initWindow();
public:
	Game();
	~Game();

	void run();
	void pollEvent();

	void update();
	void render();
};

