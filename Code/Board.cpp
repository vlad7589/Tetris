#include "Board.h"

Board::Board()
{
	this->initVariables();
	this->createGrid();
}

void Board::createGrid()
{
	for (int i = 0; i <= COLUMNS; i++)
	{
		this->columnsVertex[i * 2] = sf::Vertex(sf::Vector2f(START_X + i * CELL_SIZE, START_Y));
		this->columnsVertex[i * 2 + 1] = sf::Vertex(sf::Vector2f(START_X + i * CELL_SIZE, START_Y + ROWS * CELL_SIZE));

		this->columnsVertex[i * 2].color = sf::Color(105, 105, 105, 100);
		this->columnsVertex[i * 2 + 1].color = sf::Color(105, 105, 105, 100);
	}
	for (int i = 0; i <= ROWS; i++)
	{
		this->rowsVertex[i * 2] = sf::Vertex(sf::Vector2f(START_X, START_Y + i * CELL_SIZE));
		this->rowsVertex[i * 2 + 1] = sf::Vertex(sf::Vector2f(START_X + COLUMNS * CELL_SIZE, START_Y + i * CELL_SIZE));

		this->rowsVertex[i * 2].color = sf::Color(105, 105, 105, 100);
		this->rowsVertex[i * 2 + 1].color = sf::Color(105, 105, 105, 100);
	}
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(this->rowsVertex, states);
	target.draw(this->columnsVertex, states);
}

void Board::initVariables()
{
	this->rowsVertex = sf::VertexArray(sf::Lines, (ROWS + 1) * 2);
	this->columnsVertex = sf::VertexArray(sf::Lines, (COLUMNS + 1) * 2);

	this->createGrid();
}
