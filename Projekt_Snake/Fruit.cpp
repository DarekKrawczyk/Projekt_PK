#include "Fruit.h"

///
///Konstruktor i ustawienia domyœlne
/// 
Fruit::Fruit() {
	shape.setPosition(sf::Vector2f(400, 400));
	shape.setSize(sf::Vector2f(40, 40));
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(2);
	bonusScore = 0;
	bonusSpeed = 0;
}

///
///Ustawianie pozycji Owocu
/// 
void Fruit::setPoss(sf::Vector2f newPoss){
	shape.setPosition(newPoss);
}

///
///Zwracanie ca³ego owocu
/// 
sf::RectangleShape Fruit::getShape(){
	return shape;
}

///
///Zwracanie dodatkowych punktów 
/// 
int Fruit::getBonusScore(){
	return bonusScore;
}

///
///Zwracanie dodatkowej prêdkoœci
/// 
int Fruit::getBonusSpeed(){
	return bonusSpeed;
}

