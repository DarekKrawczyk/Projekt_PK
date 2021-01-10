#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Audio.hpp>
#include "Snake.h"
#include <vector>
#include <list>

class Engine {
private:
	sf::Vector2f rozdzielczosc = sf::Vector2f(1680, 1050);			//Rozdzielczosc
	sf::RenderWindow window;										//Okno
	const int FPS = 60;												//Klatki na sekunde
	const sf::Time TPF = sf::seconds(1/FPS);						//Czas na klatke
	std::vector<Snake> snake;										//Ca³e cia³o wê¿a
	int kierunek;													//Kierunek 
	int speed;														//Prêdkoœæ
	sf::Time ostatni_ruch;											//Czas od ostatniego ruchu
	std::list<int> Queue;											//Kolejka ruchów 


public:
	Engine();							//Konstruktor
	~Engine();							//Destruktor
	void draw();						//Wyœwietlanie okna
	void menu();						//Wyœwietlanie Menu
	void run();							//Pêtla gry
	void input();						//Obs³uga zdarzeñ
	void initialize_snake();			//Rysowanie wê¿a
	void add_body();					//Dodaj segment do cia³a
	void add_direction(int newDir);		//Dodaje kierunek do kolejki
	void update();						//Zmiana kierunku wê¿a
	enum kierunki {UP,DOWN,RIGHT,LEFT}; //Kierunki
};

