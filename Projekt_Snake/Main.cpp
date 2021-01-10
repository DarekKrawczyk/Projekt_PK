#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Snake.h"
#include "Menu.h"
#include "Engine.h"
#include <algorithm>

int main() {
    Engine game;
;

};

/*

            switch (event.type) {

            case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Event::KeyPressed:
                    menu.moveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.moveDown();
                    break;
                }
            };


                //-------------------- Wyœwietlenie Rozdzielczoœci-------------------------
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    for (std::size_t i = 0; i < modes.size(); ++i)
    {
        sf::VideoMode mode = modes[i];
        std::cout << "Mode #" << i << ": "
            << mode.width << "x" << mode.height << " - "
            << mode.bitsPerPixel << " bpp" << std::endl;
    }
    //-------------------------------------------------------------------------
*/    //game.run();

/*
sf::RenderWindow window;
window.create(sf::VideoMode(1680, 1050), "Okno");                      //Okno
Menu menu(window.getSize().x, window.getSize().y);                     //Menu

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
                    window.setVisible(false);
                    game.run();
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

    };
    window.clear();             //Czyszczenie okna
    menu.draw(window);          //Menu
    window.display();           //Wyœwietlanie okna
}*/