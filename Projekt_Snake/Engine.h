#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Snake.h"
#include "Apple.h"
#include "Peach.h"
#include "Wall.h"
#include <vector>
#include <list>

class Engine {
private:
	//--------Podstawy--------
	sf::Vector2f rozdzielczosc = sf::Vector2f(1920, 1080);			//Rozdzielczosc
	sf::RenderWindow window;										//Okno
	//------------------------

	//--------Zmienne---------
	sf::Time ostatni_ruch;											//Czas od ostatniego ruchu
	const int FPS = 60;												//Klatki na sekunde
	int kierunek;													//Kierunek 
	int speed;														//Prêdkoœæ
	int fruit_amount;												//Ilosc owoców do dodania
	int last_game_state;											//Ostatni status gry
	int game_state;													//Status gry
	unsigned int score;												//Wynik 
	unsigned int max_snake_size = 1150;								//Maksymalny rozmiar wê¿a
	//------------------------

	//--------Obiekty---------
	Apple apple;													//Jab³ko
	Peach peach;													//Brzoskwinia
	std::vector<Snake> snake;										//Vektor segmentów cia³a Snake
	std::vector<Wall> wall;											//Vektor segmentów cia³a Wall
	std::list<int> Queue;											//Kolejka ruchów 
	//------------------------

	//--------DŸwiêki---------
	sf::SoundBuffer pick_up;										//Za³adowanie dziwiêku podnoszenie jab³ka
	sf::Sound pick_up_sound;										//Zmienna korzystaj¹ca z dzwiêku podnoszenia
	sf::Music game_music;											//Muzyka t³a
	//------------------------

	//---------Text-----------
	sf::Font font;													//Czcionka
	sf::Text score_text;											//Tekst - iloœæ punktów
	sf::Text score_text_napis;										//Tekst - "Score -"
	sf::Text game_over_text;										//Tekst - "GAME OVER"
	sf::Text game_over_enter_text;									//Tekst - "Press Enter"
	sf::Text pause_text;											//Tekst - "PAUSE"
	sf::Text pause_space_text;										//Tekst - "Press space"
	sf::Text won_text;											    //Tekst - "Won"
	sf::Text esc_text;											    //Tekst - "Won"
	//------------------------

public:
	Engine();														//Konstruktor
	~Engine();														//Destruktor
	void draw();													//Wyœwietlanie okna
	void menu();													//Wyœwietlanie Menu
	void run();														//Pêtla gry
	void input();													//Obs³uga zdarzeñ
	void initialize_snake();										//Pierwszy w¹¿
	void initialize_wall();									     	//Rysowanie œcian
	void add_body();												//Dodaj segment do cia³a
	void add_direction(int newDir);									//Dodaj kierunek do kolejki
	void update();													//Update czynnikow gry
	enum kierunki {UP,DOWN,RIGHT,LEFT};								//Dostepne kierunki do poruszania
	enum states{RUNNING, GAME_OVER, PAUSE, WON};					//Dostepne statusy gry
	int randomNumber(int rozdzielczosc);							//Losowanie pozycji do jab³ka
	void pause();                                                   //Pause manager
	void startStats();												//Pocz¹tkowe statystyki
	void text(sf::Text* text, sf::Font& font, const sf::String &value, int size, sf::Color color);//Dodawnie tekstu
	void move_apple();												//Zmiana pozycji jab³ka, sprawdzenie pozycji 
	void move_peach();												//Zmiana pozycji brzoskwini, sprawdzenie pozycji 
};

