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
    while (window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event)) {

            //---------------------------- Przyciski Menu--------------------------
            switch (event.type) {

            case sf::Event::KeyPressed:

                switch (event.key.code) {

                case sf::Keyboard::Up:                            //Strza�ka w g�r�
                    menu.moveUp();
                    std::cout << "Up" << std::endl;
                    break;

                case sf::Keyboard::Down:                          //Strza�ka w d�
                    menu.moveDown();
                    std::cout << "Down" << std::endl;
                    break;

                case sf::Keyboard::Return:                        //Operacje po wci�ni�ciu enter
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
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { //Obs�uga wyj�cia przyciskiem Escape
                    window.close();
                }
            }
        };
        window.clear();             //Czyszczenie okna
        menu.draw(window);          //Menu
        window.display();           //Wy�wietlanie okna
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
    sf::Clock clock;
    initialize_snake();
    speed = 6;
    ostatni_ruch = sf::Time::Zero;
    kierunek = kierunki::UP;
	while (window.isOpen()) {
        sf::Time time = clock.restart();
        ostatni_ruch += time;
		input();
        update();
		draw();
	}
};

void Engine::input() {
	sf::Event event;

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {						//Obs�uga wyj�cia zamkni�ciem okna
			window.close();
		}

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) {           //Obs�uga wyj�cia przyciskiem Escape
				window.close();
			}
		}

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {               //Ruch w g�r�
                add_direction(kierunki::UP);
            }
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Down) {             //Ruch w d�
                add_direction(kierunki::DOWN);
            }
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Right) {             //Ruch w prawo
                add_direction(kierunki::RIGHT);
            }
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) {            //Ruch w lewo
                add_direction(kierunki::LEFT);
            }
        }

	}
}

void Engine::initialize_snake() {
	snake.clear();										//Czyszczenie vektora 
	snake.emplace_back(sf::Vector2f(800, 320));			//Dodanie G�owy w�a w vektorze
	snake.emplace_back(sf::Vector2f(800, 360));			//Dodanie 1 segmentu w�a w vektorze
	snake.emplace_back(sf::Vector2f(800, 400));			//Dodanie 2 segmentu w�a w vektorze
}

void Engine::add_body() {
	sf::Vector2f newBody = snake[snake.size()-1].getPoss();
	snake.emplace_back(newBody);
}

void Engine::add_direction(int newDir) {
    if (Queue.empty()) {
        Queue.emplace_back(newDir);
    }

    else if (Queue.back() != newDir) {
        Queue.emplace_back(newDir);
    }
};


void Engine::update() {
    if (ostatni_ruch.asSeconds() >= (sf::seconds(1.0 / float(speed)).asSeconds())) {
        sf::Vector2f thisBody = snake[0].getPoss();         //Nowa pozycja g�owy
        sf::Vector2f lastBody = thisBody;                   //Stara pozycja g�owy

        if (!Queue.empty()) {                               //Je�eli cos jest w kolejce
            switch (kierunek) {                             //Upewniamy sie �eby w�� sie nie cofa�
            case kierunki::UP:
                if (Queue.front() != kierunki::DOWN) {
                    kierunek = Queue.front();
                    std::cout << "UP" << std::endl;
                }
                break;
            case kierunki::DOWN:
                if (Queue.front() != kierunki::UP) {
                    kierunek = Queue.front();
                    std::cout << "DOWN" << std::endl;
                }
                break;
            case kierunki::RIGHT:
                if (Queue.front() != kierunki::LEFT) {
                    kierunek = Queue.front();
                    std::cout << "RIGHT" << std::endl;
                }
                break;
            case kierunki::LEFT:
                if (Queue.front() != kierunki::RIGHT) {
                    kierunek = Queue.front();
                    std::cout << "LEFT" << std::endl;
                }
                break;
            }
            Queue.pop_front();                                  //Usuni�cie elementu kt�ry zosta� obs�u�ony
        }

        switch (kierunek) {                                     //Ruchy g�owy w�a
        case kierunki::UP:
            snake[0].setPoss(sf::Vector2f(thisBody.x, thisBody.y - 40));
            break;
        case kierunki::DOWN:
            snake[0].setPoss(sf::Vector2f(thisBody.x, thisBody.y + 40));
            break;
        case kierunki::LEFT:
            snake[0].setPoss(sf::Vector2f(thisBody.x - 40, thisBody.y));
            break;
        case kierunki::RIGHT:
            snake[0].setPoss(sf::Vector2f(thisBody.x + 40, thisBody.y));
            break;
        }


        for (int i = 1; i < snake.size(); i++) {               //Ruchy g�owy
            thisBody = snake[i].getPoss();
            snake[i].setPoss(lastBody);
            lastBody = thisBody;
        }

        for (auto& i : snake) {                                 //Update po�o�enia w�a
            i.update();
        }

        ostatni_ruch = sf::Time::Zero;

    };
};
