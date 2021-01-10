#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Engine.h"

class Menu{
private:
	int rozmiar_menu = 72;							//Rozmiar czcionki w menu
	int ilosc_opcji = 3;							//Ilosc pozycji w menu
	int wybrany;									//Numer wybranej pozycji
	sf::Font font;									//Czcionka
	sf::Text menu[3];								//Pozycje w menu
	sf::Texture texture;							//Tekstura t³a
	sf::SoundBuffer buffer;							//Za³adowanie dziwiêku zmiany opcji w menu do bufferu
	sf::Sound sound;								//Zmienna korzystaj¹ca z bufferu

public:
	Menu(int width, int height);					//Konstruktor(rozmiary okna)
	~Menu();										//Destruktor
	void draw(sf::RenderWindow& window);			//Rysowanie menu
	void moveUp();									//Ruch w górê
	void moveDown();								//Ruch w dó³
	int Pressed() { return wybrany; };				//Wartoœæ wybranej opcji
	sf::Music music;								//Muzyka t³a

};

