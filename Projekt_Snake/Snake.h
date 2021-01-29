#pragma once
#include <SFML/Graphics.hpp>

class Snake {
private:
	sf::Vector2f snake_poss;									//Pozycja segmentu wê¿a
	sf::RectangleShape snake_shape;								//Reprezentacja cia³a segmentu wê¿a

public:
	Snake(sf::Vector2f StartPos, sf::Color color);				//Konstruktor
	~Snake();													//Destruktor
	sf::Vector2f getPoss() { return snake_poss; };				//Zwrócenie pozycji cia³a wê¿a
	sf::RectangleShape getShape() { return snake_shape; };		//Zwrócenie segmentu cia³a wê¿a
	void setPoss(sf::Vector2f newPoss);							//Ustawianie nowej pozycji 
	void update();												//Ustawianie nowej pozycji segmentu cia³a
};

