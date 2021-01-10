#pragma once
#include <SFML/Graphics.hpp>

class Snake {
private:
	sf::Vector2f pozycja;						//Pozycja wê¿a
	sf::RectangleShape body;					//Cia³o wê¿a

public:
	Snake(sf::Vector2f StartPos);				//Konstruktor
	~Snake();									//Destruktor
	sf::Vector2f getPoss();						//Zwrócenie pozycji cia³a wê¿a
	sf::RectangleShape getBody();				//Zwrócenie segmentu cia³a wê¿a
	void setPoss(sf::Vector2f newPoss);			//Uswanienie nowej pozycji
	void update();								//Update pozycji

};

