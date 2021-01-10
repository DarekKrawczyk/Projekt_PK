#pragma once
#include <SFML/Graphics.hpp>

class Snake {
private:
	sf::Vector2f pozycja;						//Pozycja w�a
	sf::RectangleShape body;					//Cia�o w�a

public:
	Snake(sf::Vector2f StartPos);				//Konstruktor
	~Snake();									//Destruktor
	sf::Vector2f getPoss();						//Zwr�cenie pozycji cia�a w�a
	sf::RectangleShape getBody();				//Zwr�cenie segmentu cia�a w�a
	void setPoss(sf::Vector2f newPoss);			//Uswanienie nowej pozycji
	void update();								//Update pozycji

};

