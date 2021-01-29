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
	int speed;														//Pr�dko��
	int fruit_amount;												//Ilosc owoc�w do dodania
	int last_game_state;											//Ostatni status gry
	int game_state;													//Status gry
	unsigned int score;												//Wynik 
	unsigned int max_snake_size = 1150;								//Maksymalny rozmiar w�a
	//------------------------

	//--------Obiekty---------
	Apple apple;													//Jab�ko
	Peach peach;													//Brzoskwinia
	std::vector<Snake> snake;										//Vektor segment�w cia�a Snake
	std::vector<Wall> wall;											//Vektor segment�w cia�a Wall
	std::list<int> Queue;											//Kolejka ruch�w 
	//------------------------

	//--------D�wi�ki---------
	sf::SoundBuffer pick_up;										//Za�adowanie dziwi�ku podnoszenie jab�ka
	sf::Sound pick_up_sound;										//Zmienna korzystaj�ca z dzwi�ku podnoszenia
	sf::Music game_music;											//Muzyka t�a
	//------------------------

	//---------Text-----------
	sf::Font font;													//Czcionka
	sf::Text score_text;											//Tekst - ilo�� punkt�w
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
	void draw();													//Wy�wietlanie okna
	void menu();													//Wy�wietlanie Menu
	void run();														//P�tla gry
	void input();													//Obs�uga zdarze�
	void initialize_snake();										//Pierwszy w��
	void initialize_wall();									     	//Rysowanie �cian
	void add_body();												//Dodaj segment do cia�a
	void add_direction(int newDir);									//Dodaj kierunek do kolejki
	void update();													//Update czynnikow gry
	enum kierunki {UP,DOWN,RIGHT,LEFT};								//Dostepne kierunki do poruszania
	enum states{RUNNING, GAME_OVER, PAUSE, WON};					//Dostepne statusy gry
	int randomNumber(int rozdzielczosc);							//Losowanie pozycji do jab�ka
	void pause();                                                   //Pause manager
	void startStats();												//Pocz�tkowe statystyki
	void text(sf::Text* text, sf::Font& font, const sf::String &value, int size, sf::Color color);//Dodawnie tekstu
	void move_apple();												//Zmiana pozycji jab�ka, sprawdzenie pozycji 
	void move_peach();												//Zmiana pozycji brzoskwini, sprawdzenie pozycji 
};

