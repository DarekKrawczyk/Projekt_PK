#include "Engine.h"
#include "Menu.h"
#include <iostream>

Engine::Engine() {
	window.create(sf::VideoMode(rozdzielczosc.x, rozdzielczosc.y), "Snake", sf::Style::Default);
	window.setFramerateLimit(FPS);
    menu();
};

Engine::~Engine() {

};

void Engine::menu() {
    Menu menu(window.getSize().x, window.getSize().y);                     //Menu
    menu.music.play();
    menu.music.setVolume(2);
	menu.music.setLoop(true);
    while (window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event)) {

            //---------------------------- Przyciski Menu--------------------------
            switch (event.type) {

            case sf::Event::KeyPressed:

                switch (event.key.code) {

                case sf::Keyboard::Up:                            //Strza³ka w górê
                    menu.moveUp();
                    std::cout << "Up" << std::endl;
                    break;

                case sf::Keyboard::Down:                          //Strza³ka w dó³
                    menu.moveDown();
                    std::cout << "Down" << std::endl;
                    break;

                case sf::Keyboard::Return:                        //Wybranie opcji
                    switch (menu.Pressed()) {
                    case 0:
                        std::cout << "New Game" << std::endl;
                        menu.music.stop();
                        run();
                        break;
                    case 1:
                        std::cout << "Settings" << std::endl;
                        break;
                    case 2:
                        std::cout << "Exit" << std::endl;
                        window.close();
                        break;
                    }
                }
            };
            //-------------------------------------------------------------------

            if (event.type == sf::Event::Closed) {
                window.close();
            };

            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { //Obs³uga wyjœcia przyciskiem Escape
                    window.close();
                }
            }

        };
        window.clear();             //Czyszczenie okna
        menu.draw(window);          //Menu
        window.display();           //Wyœwietlanie okna
    }
}

void Engine::draw() {
	window.clear();
	for (auto& s : snake) {
		window.draw(s.getBody());
	}
	window.display();
};

void Engine::run() {
    draw_snake();
	while (window.isOpen()) {
		input();
		draw();
	}
};

void Engine::input() {
	sf::Event event;

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {						//Obs³uga wyjœcia zamkniêciem okna
			window.close();
		}

		if (event.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { //Obs³uga wyjœcia przyciskiem Escape
				window.close();
			}
		}
	}
}

void Engine::draw_snake() {
	snake.clear();										//Czyszczenie vektora 
	snake.emplace_back(sf::Vector2f(800, 400));			//Dodanie G³owy wê¿a w vektorze
	snake.emplace_back(sf::Vector2f(820, 400));			//Dodanie 1 segmentu wê¿a w vektorze
	snake.emplace_back(sf::Vector2f(840, 400));			//Dodanie 2 segmentu wê¿a w vektorze
}

void Engine::add_body() {
	sf::Vector2f newBody = snake[snake.size()-1].getPoss();
	snake.emplace_back(newBody);
}
