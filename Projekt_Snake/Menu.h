#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Menu{
private:
	int rozmiar_menu = 72;							//Rozmiar czcionki w menu
	int ilosc_opcji = 3;							//Ilosc pozycji w menu
	int wybrany;									//Numer wybranej pozycji
	sf::Font font;									//Czcionka
	sf::Text menu[3];								//Pozycje w menu
	sf::Texture texture;							//Tekstura t�a
	sf::Music music;


public:
	Menu(int width, int height);					//Konstruktor(rozmiary okna)
	~Menu();										//Destruktor

	void draw(sf::RenderWindow& window);			//Rysowanie menu
	void moveUp();									//Ruch w g�r�
	void moveDown();								//Ruch w d�
	int Pressed() { return wybrany; };				//Warto�� wybranej opcji

};

