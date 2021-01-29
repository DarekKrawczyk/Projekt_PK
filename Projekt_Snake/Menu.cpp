#include "Menu.h"
#include <iostream>

Menu::Menu(int width, int height){

	///
	///Pobranie czcionki
	///
	if (!font.loadFromFile("yoster.ttf")){
		std::cout << "Error pobrania czcionki -yoster.ttf-" << std::endl;
	};

	///
	///Pobranie t³a menu
	///
	if (!texture.loadFromFile("snake_2.png")) {
		std::cout << "Error pobrania tla -snake_2.png-" << std::endl;
	};

	///
	///Pobranie muzyki t³a
	///
	if (!music.openFromFile("menu_music.ogg")) {
		std::cout << "Error pobrania muzyki -menu_music.ogg-" << std::endl;
	};
	///
	///Muzyczka w tle
	///
	music.play();
	music.setVolume(5);
	music.setLoop(true);

	///
	///DŸwiêk przejœcia pomiêdzy opcjami menu
	///
	if (!buffer.loadFromFile("menu_switch.wav")) {
		std::cout << "Error pobrania dzwieku -menu_switch.wav-" << std::endl;
	};
	///
	///Zapisanie bufferu dŸwiêku do zmiennej sound
	///
	sound.setBuffer(buffer);
	sound.setVolume(5);

	///
	///Przycisk New Game
	///
	menu[0].setFont(font); 
	menu[0].setString("New Game");
	menu[0].setCharacterSize(rozmiar_menu);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setPosition(sf::Vector2f(width / 2 - menu[0].getLocalBounds().width / 2, height / (2 + 1) * 1));
	menu[0].setOutlineColor(sf::Color::Black);
	menu[0].setOutlineThickness(10);

	///
	///Przycisk Exit
	///
	menu[1].setFont(font);
	menu[1].setString("Exit");
	menu[1].setCharacterSize(rozmiar_menu);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setPosition(sf::Vector2f(width / 2 - menu[1].getLocalBounds().width / 2, height / (2 + 1) * 2));
	menu[1].setOutlineColor(sf::Color::Black);
	menu[1].setOutlineThickness(10);

	wybrany = 0;
}

Menu::~Menu(){
}

///
///Rysowanie opcji do klikniêcia na ekranie
///
void Menu::draw(sf::RenderWindow& window){
	///
	///Tekstura t³a
	///
	sf::Sprite background(texture);
	window.draw(background);
	for (int i = 0; i < ilosc_opcji; ++i) {
		window.draw(menu[i]);
	}
}

///
///Ruch do góry w menu
///
void Menu::moveUp(){
	if (wybrany - 1 >= 0) {
		menu[wybrany].setFillColor(sf::Color::White);
		wybrany--;
		menu[wybrany].setFillColor(sf::Color::Red);
		sound.play();
	}
}

///
///Ruch na dó³ w menu
///
void Menu::moveDown(){
	if (wybrany + 1 < ilosc_opcji) {
		menu[wybrany].setFillColor(sf::Color::White);
		wybrany++;
		menu[wybrany].setFillColor(sf::Color::Red);
		sound.play();
	}
}
