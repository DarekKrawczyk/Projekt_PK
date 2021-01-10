#include "Snake.h"

Snake::Snake(sf::Vector2f StartPos) {
	body.setSize(sf::Vector2f(40, 40));
	body.setFillColor(sf::Color::Green);
	body.setPosition(StartPos);
	pozycja = StartPos;
}

Snake::~Snake() {
}

sf::Vector2f Snake::getPoss() {
	return pozycja;
}

sf::RectangleShape Snake::getBody() {
	return body;
}

void Snake::setPoss(sf::Vector2f newPoss) {
	pozycja = newPoss;
}

void Snake::update() {
	body.setPosition(pozycja);
}
