#pragma once

#include<SFML/Graphics.hpp>
#include "Const.h"
class Board : public sf::Drawable, public sf::Transformable
{
private:
	sf::VertexArray rowsVertex;
	sf::VertexArray columnsVertex;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void initVariables();
public:
	Board();

	void createGrid();
};

