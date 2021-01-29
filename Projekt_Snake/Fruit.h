#pragma once
#include<SFML/Graphics.hpp>

class Fruit {
protected:
	sf::RectangleShape shape;						//Kszta�t Owocu
	int bonusScore = 0;								//Dodatkowe punkty
	int bonusSpeed = 0;								//Dodatkowa pr�dko��
public:
	Fruit();
	virtual void setPoss(sf::Vector2f newPoss);		//Ustawianie pozycji owocu
	virtual sf::RectangleShape getShape();			//Zwracanie ca�ego owocu
	virtual int getBonusScore();					//Zwracanie dodatkowych punkt�w
	virtual int getBonusSpeed();					//Zwracanie dodatkowej pr�dko�ci
};

