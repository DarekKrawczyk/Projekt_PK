#pragma once
#include <SFML/Graphics.hpp>

class Snake {
private:
	sf::Vector2f snake_poss;									//Pozycja segmentu w�a
	sf::RectangleShape snake_shape;								//Reprezentacja cia�a segmentu w�a

public:
	Snake(sf::Vector2f StartPos, sf::Color color);				//Konstruktor
	~Snake();													//Destruktor
	sf::Vector2f getPoss() { return snake_poss; };				//Zwr�cenie pozycji cia�a w�a
	sf::RectangleShape getShape() { return snake_shape; };		//Zwr�cenie segmentu cia�a w�a
	void setPoss(sf::Vector2f newPoss);							//Ustawianie nowej pozycji 
	void update();												//Ustawianie nowej pozycji segmentu cia�a
};

