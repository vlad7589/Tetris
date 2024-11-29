#include "Game.h"
#include<ctime>
int main() {
	srand(time(0));

	Game game;

	game.run();

	return 0;
}