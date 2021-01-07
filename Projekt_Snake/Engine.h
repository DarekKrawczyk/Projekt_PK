#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Audio.hpp>
#include "Snake.h"
#include <vector>

class Engine {
private:
	sf::Vector2f rozdzielczosc = sf::Vector2f(1680, 1050);			//Rozdzielczosc
	sf::RenderWindow window;										//Okno
	const int FPS = 60;												//Klatki na sekunde
	const sf::Time TPF = sf::seconds(1/FPS);						//Czas na klatke
	std::vector<Snake> snake;										//Ca³e cia³o wê¿a
	sf::Music music;

public:
	Engine();							//Konstruktor
	~Engine();							//Destruktor
	void draw();						//Wyœwietlanie okna
	void menu();						//menu metoda
	void run();							//Pêtla gry
	void input();						//Obs³uga zdarzeñ
	void draw_snake();					//Rysowanie wê¿a
	void add_body();					//Dodaj segment do cia³a
};

