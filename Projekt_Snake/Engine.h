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
	std::vector<Snake> snake;										//Ca�e cia�o w�a
	sf::Music music;

public:
	Engine();							//Konstruktor
	~Engine();							//Destruktor
	void draw();						//Wy�wietlanie okna
	void menu();						//menu metoda
	void run();							//P�tla gry
	void input();						//Obs�uga zdarze�
	void draw_snake();					//Rysowanie w�a
	void add_body();					//Dodaj segment do cia�a
};

