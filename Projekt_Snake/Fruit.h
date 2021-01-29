#pragma once
#include<SFML/Graphics.hpp>

class Fruit {
protected:
	sf::RectangleShape shape;						//Kszta³t Owocu
	int bonusScore = 0;								//Dodatkowe punkty
	int bonusSpeed = 0;								//Dodatkowa prêdkoœæ
public:
	Fruit();
	virtual void setPoss(sf::Vector2f newPoss);		//Ustawianie pozycji owocu
	virtual sf::RectangleShape getShape();			//Zwracanie ca³ego owocu
	virtual int getBonusScore();					//Zwracanie dodatkowych punktów
	virtual int getBonusSpeed();					//Zwracanie dodatkowej prêdkoœci
};

