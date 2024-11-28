#include "Game.h"
#include<ctime>

int main() {
	srand((unsigned)time(NULL));

	Game game;

	game.run();

	return 0;
}