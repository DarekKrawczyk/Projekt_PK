#include "Menu.h"
#include <iostream>

Menu::Menu(int width, int height){

	//Pobranie czcionki
	if (!font.loadFromFile("yoster.ttf")){
		std::cout << "Error pobrania czcionki" << std::endl;
	};

	//Pobranie t³a menu
	if (!texture.loadFromFile("snake_1.png")) {
		std::cout << "Error pobrania tla" << std::endl;
	};

	//Pobranie muzyki t³a
	if (!music.openFromFile("menu_music.ogg")) {
		std::cout << "Error pobrania muzyki menu" << std::endl;
	};

	//Pobieranie dzwiêku przejscia w menu
	if (!buffer.loadFromFile("menu_switch.wav")) {
		std::cout << "Error pobrania muzyki menu switch" << std::endl;
	};

	//Pobieranie bufferu do d¿wiêku przejœcia w menu
	sound.setBuffer(buffer);
	sound.setVolume(5);

	//Odtwarzenie muzyki w menu
	music.play();
	music.setVolume(2);
	music.setLoop(true);

	//Przycisk New Game
	menu[0].setFont(font); 
	menu[0].setString("New Game");
	menu[0].setCharacterSize(rozmiar_menu);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setOrigin(menu[0].getLocalBounds().width/2, menu[0].getLocalBounds().height/2);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (ilosc_opcji + 1) * 1));

	//Przycisk Settings
	menu[1].setFont(font);
	menu[1].setString("Settings");
	menu[1].setCharacterSize(rozmiar_menu);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (ilosc_opcji + 1) * 2));

	//Przycisk Exit
	menu[2].setFont(font);
	menu[2].setString("Exit");
	menu[2].setCharacterSize(rozmiar_menu);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(sf::Vector2f(width / 2, height / (ilosc_opcji + 1) * 3));

	wybrany = 0;
}

Menu::~Menu(){
}

void Menu::draw(sf::RenderWindow& window){
	sf::Sprite background(texture);
	window.draw(background);
	for (int i = 0; i < ilosc_opcji; ++i) {
		window.draw(menu[i]);
	}
}

void Menu::moveUp(){
	if (wybrany - 1 >= 0) {
		menu[wybrany].setFillColor(sf::Color::White);
		wybrany--;
		menu[wybrany].setFillColor(sf::Color::Red);
		sound.play();
	}
}

void Menu::moveDown(){
	if (wybrany + 1 < ilosc_opcji) {
		menu[wybrany].setFillColor(sf::Color::White);
		wybrany++;
		menu[wybrany].setFillColor(sf::Color::Red);
		sound.play();
	}
}
