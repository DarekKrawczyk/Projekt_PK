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
	std::vector<Snake> snake;										//Ca�e cia�o w�a
	int kierunek;													//Kierunek 
	int speed;														//Pr�dko��
	sf::Time ostatni_ruch;											//Czas od ostatniego ruchu
	std::list<int> Queue;											//Kolejka ruch�w 


public:
	Engine();							//Konstruktor
	~Engine();							//Destruktor
	void draw();						//Wy�wietlanie okna
	void menu();						//Wy�wietlanie Menu
	void run();							//P�tla gry
	void input();						//Obs�uga zdarze�
	void initialize_snake();			//Rysowanie w�a
	void add_body();					//Dodaj segment do cia�a
	void add_direction(int newDir);		//Dodaje kierunek do kolejki
	void update();						//Zmiana kierunku w�a
	enum kierunki {UP,DOWN,RIGHT,LEFT}; //Kierunki
};

