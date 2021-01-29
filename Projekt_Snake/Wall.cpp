#include "Wall.h"

///
///Konstruktor i w³asnoœci dla segmentu œciany
/// 
Wall::Wall(sf::Vector2f position) {
	wall_shape.setSize(sf::Vector2f(40, 40));
	wall_shape.setFillColor(sf::Color(84, 50, 10));
	wall_shape.setPosition(position);
	wall_shape.setOutlineColor(sf::Color::Black);
	wall_shape.setOutlineThickness(2);
}

///
///Zwracanie ca³ej œciany
/// 
sf::RectangleShape Wall::getShape() {
	return wall_shape;
}
