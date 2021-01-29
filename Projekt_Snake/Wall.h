#pragma once
#include <SFML/Graphics.hpp>

class Wall{
private:

	sf::RectangleShape wall_shape;		//Segment �ciany
	sf::Vector2f wall_poss;				//Pozycja segmentu �ciany

public:
	Wall(sf::Vector2f position);        //Konstruktor
	sf::RectangleShape getShape();      //Zwracanie elementu �ciany
};

