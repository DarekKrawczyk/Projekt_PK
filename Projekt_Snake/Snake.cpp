#include "Snake.h"

///
///konstruktor 
/// 
Snake::Snake(sf::Vector2f StartPos, sf::Color color) {
	snake_shape.setSize(sf::Vector2f(40, 40));
	snake_shape.setFillColor(color);
	snake_shape.setPosition(StartPos);
	snake_shape.setOutlineColor(sf::Color::Black);
	snake_shape.setOutlineThickness(2);
	snake_poss = StartPos;
}

///
///Destruktor
/// 
Snake::~Snake() {
}

///
///Ustawianie pozycji wektora
/// 
void Snake::setPoss(sf::Vector2f newPoss) {
	snake_poss = newPoss;
}

///
///Update pozycji sengmentu cia³a
/// 
void Snake::update() {
	snake_shape.setPosition(snake_poss);
}
