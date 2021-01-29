#pragma once
#include <SFML/Graphics.hpp>

class Wall{
private:

	sf::RectangleShape wall_shape;		//Segment œciany
	sf::Vector2f wall_poss;				//Pozycja segmentu œciany

public:
	Wall(sf::Vector2f position);        //Konstruktor
	sf::RectangleShape getShape();      //Zwracanie elementu œciany
};

