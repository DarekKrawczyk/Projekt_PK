#include "Engine.h"
#include "Menu.h"
#include <iostream>

///
///Konstruktor
/// 
Engine::Engine() {
    ///
    ///Tworzenie okna gry
    /// 
	window.create(sf::VideoMode(rozdzielczosc.x, rozdzielczosc.y), "Snake", sf::Style::Default);    
    ///
    ///Ustawianie limitu FPS
    /// 
	window.setFramerateLimit(FPS);                                                                      

    ///
    ///Pobieranie dzwięku w tle gry
    /// 
    if (!game_music.openFromFile("game_music.ogg")) {
        std::cout << "Error pobrania muzyki -game_music.ogg-" << std::endl;
    };

    ///
    ///Pobieranie dzwięku pick up
    /// 
    if (!pick_up.loadFromFile("pick_up.wav")) {
        std::cout << "Error pobrania muzyki -pick_up.wav-" << std::endl;
    };
    ///
    ///Ustawienia dźwięku pick up
    /// 
    pick_up_sound.setBuffer(pick_up);
    pick_up_sound.setVolume(5);

    ///
    ///Pobranie czcionki
    /// 
    if (!font.loadFromFile("yoster.ttf")) {
        std::cout << "Error pobrania czcionki -yoster.ttf-" << std::endl;
    };

    ///
    ///Napis GAME OVER
    /// 
    text(&game_over_text, font, "GAME OVER", 100, sf::Color::White);
    game_over_text.setPosition(sf::Vector2f(rozdzielczosc.x / 2 - game_over_text.getLocalBounds().width / 2, rozdzielczosc.y / (2 + 1) * 1));
    game_over_text.setOutlineColor(sf::Color::Black);
    game_over_text.setOutlineThickness(10);

    ///
    ///Napis Press Enter to retry
    /// 
    text(&game_over_enter_text, font, "Press Enter to retry", 60, sf::Color::White);
    game_over_enter_text.setPosition(sf::Vector2f(rozdzielczosc.x / 2 - game_over_enter_text.getLocalBounds().width / 2, rozdzielczosc.y / (2 + 1) * 1.5));
    game_over_enter_text.setOutlineColor(sf::Color::Black);
    game_over_enter_text.setOutlineThickness(10);

    ///
    ///Napis PAUSE
    /// 
    text(&pause_text, font, "PAUSE", 100, sf::Color::White);
    pause_text.setPosition(sf::Vector2f(rozdzielczosc.x / 2 - pause_text.getLocalBounds().width / 2, rozdzielczosc.y / (2 + 1) * 1));
    pause_text.setOutlineColor(sf::Color::Black);
    pause_text.setOutlineThickness(10);

    ///
    ///Napis Press Space to continue
    /// 
    text(&pause_space_text, font, "Press Space to continue", 60, sf::Color::White);
    pause_space_text.setPosition(sf::Vector2f(rozdzielczosc.x / 2 - pause_space_text.getLocalBounds().width / 2, rozdzielczosc.y / (2 + 1) * 1.5));
    pause_space_text.setOutlineColor(sf::Color::Black);
    pause_space_text.setOutlineThickness(10);

    ///
    ///Napis Score
    /// 
    text(&score_text, font, "Score = 0", 45, sf::Color::White);
    score_text.setPosition(sf::Vector2f(rozdzielczosc.x / 2 - score_text.getLocalBounds().width / 2, -9));
    score_text.setOutlineColor(sf::Color::Black);
    score_text.setOutlineThickness(5);

    ///
    ///Napis You WON
    /// 
    text(&won_text, font, "You WON", 100, sf::Color::White);
    won_text.setPosition(sf::Vector2f(rozdzielczosc.x / 2 - won_text.getLocalBounds().width / 2, rozdzielczosc.y / (2 + 1) * 1));
    won_text.setOutlineColor(sf::Color::Black);
    won_text.setOutlineThickness(10);

    ///
    ///Napis Press Esc to exit the game
    /// 
    text(&esc_text, font, "Press Esc to exit the game", 60, sf::Color::White);
    esc_text.setPosition(sf::Vector2f(rozdzielczosc.x / 2 - esc_text.getLocalBounds().width / 2, rozdzielczosc.y / (2 + 1) * 2));
    esc_text.setOutlineColor(sf::Color::Black);
    esc_text.setOutlineThickness(10);

    ///
    ///Uruchowmienie Menu gry
    /// 
    menu();    
};

///
///Destruktor
/// 
Engine::~Engine() {

};

///
///Menu gry
/// 
void Engine::menu() {
    ///
    ///Okno menu o rozmiarach okna gry
    /// 
    Menu menu(window.getSize().x, window.getSize().y);                     
    sf::Event event;

    while (window.isOpen()){

        while (window.pollEvent(event)) {

            ///
            ///Typ zdarzenia
            /// 
            switch (event.type) {

            ///
            ///Wciśnięty klawisz
            /// 
            case sf::Event::KeyPressed:

                ///
                ///Kod klawiszy
                /// 
                switch (event.key.code) {
                   
                ///
                ///Strzałka w górę
                /// 
                case sf::Keyboard::Up:
                    menu.moveUp();
                    std::cout << "Up" << std::endl;
                    break;

                ///
                ///Strzałka w dół
                ///
                case sf::Keyboard::Down:
                    menu.moveDown();
                    std::cout << "Down" << std::endl;
                    break;

                ///
                ///Escape
                ///
                case sf::Keyboard::Escape:
                    window.close();
                    break;

                ///
                ///Enter
                ///
                case sf::Keyboard::Return:
                    switch (menu.Pressed()) {
                    case 0:
                        std::cout << "New Game" << std::endl;
                        menu.music.stop();
                        run();
                        break;
                    case 1:
                        std::cout << "Exit" << std::endl;
                        window.close();
                        break;
                    }
                }
                break;

            ///
            ///Zamknięcie okna
            ///
            case sf::Event::Closed:
                window.close();
                break;
            };
        };
        ///
        ///Czyszczenie okna
        ///
        window.clear();
        ///
        ///Rysowanie Menu 
        ///
        menu.draw(window);      
        ///
        ///Wyświetlania zawartości
        ///      
        window.display();

    }
}

///
///Rysowanie na ekran
/// 
void Engine::draw() {
    ///
    ///Tło
    /// 
	window.clear(sf::Color(20, 138, 4));

    ///
    ///Ściany
    /// 
    for (auto& i : wall) {
        window.draw(i.getShape());
    }

    ///
    ///Owoce
    /// 
    window.draw(apple.getShape());
    window.draw(peach.getShape());

    ///
    ///Wąż
    /// 
	for (auto& s : snake) {
		window.draw(s.getShape());
	}

    ///
    ///Wynik
    /// 
    window.draw(score_text);

    ///
    ///Koniec gry
    /// 
    if (game_state == states::GAME_OVER) {
        window.draw(game_over_text);
        window.draw(game_over_enter_text);
        window.draw(esc_text);
        game_music.stop();
    }

    ///
    ///Wygrana gra
    /// 
    if (game_state == states::WON) {
        window.draw(won_text);
        window.draw(game_over_enter_text);
        window.draw(esc_text);
        game_music.stop();
    }

    ///
    ///PAUZA
    /// 
    if (game_state == states::PAUSE) {
        window.draw(pause_text);
        window.draw(pause_space_text);
        window.draw(esc_text);
        game_music.pause();
    }

    ///
    ///Wznownienie muzyki
    /// 
    if (game_state == states::RUNNING and last_game_state==states::PAUSE) {
        game_music.play();
        //TODO - muzyka powraca tam gdzie była przed pause
    }

    ///
    ///Wyświetlanie klatki
    /// 
	window.display();
};

///
///Pętla gry
/// 
void Engine::run() {
    ///
    ///Ustawienia początkowe
    /// 
    startStats();

    ///
    ///Zegar odliczający czas do kolejnego update'u gry
    /// 
    sf::Clock clock;

	while (window.isOpen()) {
        sf::Time time = clock.restart();
        ///
        ///Etapy gry
        /// 
        if (game_state == states::GAME_OVER || game_state == states::PAUSE || game_state==states::WON) {
            input();

            if (game_state == states::GAME_OVER) {
                std::cout << "Game over" << std::endl;
                draw();
            }

            if (game_state == states::WON) {
                std::cout << "Game Won" << std::endl;
                draw();
            }

            if (game_state == states::PAUSE) {
                std::cout << "Pause" << std::endl;
                draw();
            }

            continue;
        }
        ostatni_ruch += time;
        ///
        ///Obsługa wejścia, zmiana wartości, oraz wyświetlanie gry
        /// 
		input();
        update();
		draw();
	}
};

///
///Obsługa klawiszy podczas gry
/// 
void Engine::input() {
    ///
    ///Nowe zdarzenie
    /// 
	sf::Event event;

	while (window.pollEvent(event)) {
        ///
        ///Typ zdarzenia
        /// 
        switch (event.type) {

        ///
        ///Zamykanie okna
        /// 
        case sf::Event::Closed:
            window.close();
            break;

        ///
        ///Wciśnięty klawisz
        /// 
        case sf::Event::KeyPressed:

            ///
            ///Kod klawiszy
            /// 
            switch (event.key.code) {

            case sf::Keyboard::Space:
                pause();
                break;

            case sf::Keyboard::R:
                game_state = states::WON;
                break;

            case sf::Keyboard::Up:
                add_direction(kierunki::UP);
                break;

            case sf::Keyboard::Down:
                add_direction(kierunki::DOWN);
                break;

            case sf::Keyboard::Left:
                add_direction(kierunki::LEFT);
                break;

            case sf::Keyboard::Right:
                add_direction(kierunki::RIGHT);
                break;
            }
        }
        
        ///
        ///Zdarzenie - wygrana gra
        /// 
        if (game_state == states::WON) {
            if (event.key.code == sf::Keyboard::Enter) {
                startStats();
            }
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        ///
        ///Zdarzenie - przegrana gra
        /// 
        if (game_state == states::GAME_OVER) {
            if (event.key.code == sf::Keyboard::Enter) {
                startStats();
            }
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        ///
        ///Zdarzenie - pause
        /// 
        if (game_state == states::PAUSE) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
    }
}

///
///Pierwszy snake
/// 
void Engine::initialize_snake() {
    snake.clear();		
    ///
    ///Głowa Snake'a i pierwsze 2 segmenty ciała
    /// 
    snake.emplace_back(sf::Vector2f(800, 320), sf::Color::Yellow);			
    snake.emplace_back(sf::Vector2f(800, 360), sf::Color::Green);			
    snake.emplace_back(sf::Vector2f(800, 400), sf::Color::Green);			
}

///
///Ściana
/// 
void Engine::initialize_wall() {
    wall.clear();				
    ///
    ///Dodawanie wektorów ścian poziomych
    /// 
    for (int i = 0; i < (rozdzielczosc.x / 40); i++) {
        wall.emplace_back(sf::Vector2f(40 * i, 0));
        wall.emplace_back(sf::Vector2f(40 * i, 1040));
    }		
    ///
    ///Dodawanie wektorów ścian pionowych
    /// 
    for (int i = 0; i < (rozdzielczosc.y / 40); i++) {
        wall.emplace_back(sf::Vector2f(0, 40 * i));
        wall.emplace_back(sf::Vector2f(1880, 40 * i));
    }
}

///
///Dodanie ciała na ostatniej pozycji ogonu
/// 
void Engine::add_body() {
    sf::Vector2f newBody = snake[snake.size() - 1].getPoss();
     snake.emplace_back(newBody, sf::Color::Green);
}

///
///Dodawanie do kolejki
/// 
void Engine::add_direction(int newDir) {
    ///
    ///Gdy kolejka jest pusta to dodajemy
    /// 
    if (Queue.empty()) {
        Queue.emplace_back(newDir);
    }

    ///
    ///Dodajemy ruchy które nie są zduplikowane
    /// 
    else if (Queue.back() != newDir) {
        Queue.emplace_back(newDir);
    }
};

///
///Ruchy węża, kolejka, kolizje
/// 
void Engine::update() {

    ///
    ///Wygranie gry 
    /// 
    if (snake.size() == max_snake_size) {
        game_state = states::WON;
    }

    ///
    ///Czy upłynęło wystarczająco czasu
    /// 
    if (ostatni_ruch.asSeconds() >= (sf::seconds(1.0 / float(speed)).asSeconds())) {
        ///
        ///Nowa pozycja głowy
        /// 
        sf::Vector2f thisBody = snake[0].getPoss();        
        ///
        ///Pozycja ostatniego wybranego segmentu
        /// 
        sf::Vector2f lastBody = thisBody;                

        ///
        ///Gdy kolejka coś ma
        /// 
        if (!Queue.empty()) {                               
            switch (kierunek) {     
            ///
            ///Upewnienie się że gdy idziemy do góry to następny ruch nie będzie w dół, tak samo jak lewo-prawo
            /// 
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
            ///
            ///Obsłużony ruch nie jest już potrzebny
            /// 
            Queue.pop_front();                                  
        }

        ///
        ///Zwiększanie długości węża
        /// 
        if (fruit_amount) {
            add_body();
            fruit_amount--;
        }

        ///
        ///Ruchy głowy węża w zależności od kierunku obsłużonego w kolejce lub gdy kolejka jest pusta, po prostu kierunku
        /// 
        switch (kierunek) {                                   
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

        ///
        ///Zmiana położenia wektorów położania węża - podążanie za głową
        /// 
        for (int i = 1; i < snake.size(); i++) {               
            thisBody = snake[i].getPoss();
            snake[i].setPoss(lastBody);
            lastBody = thisBody;
        }

        ///
        ///Update położania sementów ciała więża wzlgędem wcześniejszych operacji
        /// 
        for (auto& i : snake) {    
            i.update();
        }

        ///
        ///.left - odległość od lewej ściany|.top - odległość od górnej ściany|.width - szerokość segmentu|.heigth - wysokość segmentu
        ///
        
        ///
        ///Detekcja kolizii =>  Snake - Snake
        /// 
        sf::FloatRect snakeHead = snake[0].getShape().getGlobalBounds();
        for (int i = 3; i < snake.size(); i++) {
            sf::FloatRect snakeRect = snake[i].getShape().getGlobalBounds();
            if (snakeHead.left == snakeRect.left && snakeHead.top == snakeRect.top) {
                game_state = states::GAME_OVER;
                break;
            }
        }
        ///
        ///Detekcja kolizii =>  Snake - Wall
        /// 
        if ((snakeHead.left < 0 || snakeHead.left + snakeHead.width > rozdzielczosc.x) || (snakeHead.top < 0 || snakeHead.top + snakeHead.height > rozdzielczosc.y)) {
            std::cout << "Snake - Wall" << std::endl;
            game_state = states::GAME_OVER;
        }

        ///
        ///Detekcja kolizii =>  Snake - Apple
        /// 
        sf::FloatRect applePos = apple.getShape().getGlobalBounds();
        if (snakeHead.top == applePos.top && snakeHead.left == applePos.left) {
            std::cout << "Snake - Apple" << std::endl;
            score += 1 + apple.getBonusScore();
            fruit_amount++;
            speed += apple.getBonusSpeed();
            move_apple();
            pick_up_sound.play();
            score_text.setString("Score = "+std::to_string(score));
            score_text.setPosition(sf::Vector2f(rozdzielczosc.x / 2 - score_text.getLocalBounds().width / 2, -9));
        }

        ///
        ///Detekcja kolizii =>  Snake -Peach
        /// 
        sf::FloatRect peachPos = peach.getShape().getGlobalBounds();
        if (snakeHead.top == peachPos.top && snakeHead.left == peachPos.left) {
            std::cout << "Snake - Peach" << std::endl;
            fruit_amount+=2;
            speed += peach.getBonusSpeed();
            move_peach();
            pick_up_sound.play();
            score += peach.getBonusScore();
            score_text.setString("Score = "+std::to_string(score));
            score_text.setPosition(sf::Vector2f(rozdzielczosc.x / 2 - score_text.getLocalBounds().width / 2, -9));
        }

        ///
        ///Zarowanie czasu
        /// 
        ostatni_ruch = sf::Time::Zero;
    };
}

///
///Losowanie nowej pozycji jabłka lub brzoskwini
/// 
int Engine::randomNumber(int rozdzielczosc) {
    int randomNumber = 0;
    for (;;) {
        randomNumber = (rand() % rozdzielczosc) + 1;
        if (randomNumber % 40 == 0) {
            break;
        }
    }
    return randomNumber;
}

///
///Pause Manager
/// 
void Engine::pause() {
    ///
    ///Pauzowanie gry
    /// 
    if (game_state == states::RUNNING) {
        last_game_state = game_state;
        game_state = states::PAUSE;
    }
    ///
    ///Odpauzowywanie gry
    /// 
    else if (game_state == states::PAUSE) {
        game_state = last_game_state;
    }
}

///
///Ustawienia startowe
/// 
void Engine::startStats() {
    srand(time(nullptr));
    ///
    ///Muzyka
    /// 
    game_music.play();
    game_music.setVolume(5);
    game_music.setLoop(true);
    ///
    ///Wartości gry
    /// 
    score = 0;
    fruit_amount = 0;
    speed = 6;
    Queue.clear();
    ostatni_ruch = sf::Time::Zero;
    kierunek = kierunki::UP;
    game_state = states::RUNNING;
    last_game_state = game_state;
    ///
    ///Jabłko, brzoskwinia, ściana i pierwszy wąż
    /// 
    move_apple();
    move_peach();
    initialize_snake();
    initialize_wall();
    ///
    ///Inicjalizacja pierwszego napisu z punktacją
    /// 
    //sf::FloatRect scoreTextBounds = score_text.getLocalBounds();
    score_text.setString("Score = "+std::to_string(score));
    score_text.setPosition(sf::Vector2f(rozdzielczosc.x/2 - score_text.getLocalBounds().width /2, -9));
}

///
///Wstawianie tekstu
/// 
void Engine::text(sf::Text* text, sf::Font& font, const sf::String &value, int size, sf::Color color) {
    text->setFont(font);
    text->setString(value);
    text->setCharacterSize(size);
    text->setFillColor(color);
}

///
///Nowa pozycje brzoskwini
/// 
void Engine::move_peach(){
    sf::Vector2f new_peach_poss;
    bool change_poss = false;
    do {
        change_poss = false;
        ///
        ///Losowanie wartości
        /// 
        new_peach_poss.x = randomNumber(rozdzielczosc.x);
        new_peach_poss.y = randomNumber(rozdzielczosc.y);

        ///
        ///Sprawdzenie czy owoc jest w wynaczonym polu
        /// 
        if ((new_peach_poss.y > rozdzielczosc.y - 80 || new_peach_poss.y < 80) || (new_peach_poss.x > rozdzielczosc.x - 80 || new_peach_poss.x < 80)) {
            change_poss = true;
        }

        ///
        ///Sprawdzanie kolizji jabłka ciałem węża 
        /// 
        for (auto& i : snake) {
            if (i.getShape().getGlobalBounds().intersects(sf::FloatRect(new_peach_poss.x, new_peach_poss.y, 40, 40))) {
                change_poss = true;
                break;
            }
        }

        peach.setPoss(new_peach_poss);
    } while (change_poss);
    std::cout << "Peach x: " << new_peach_poss.x << " y: " << new_peach_poss.y << std::endl;
};

///
///Nowa pozycja jabłka
/// 
void Engine::move_apple() {
    sf::Vector2f new_fruit_poss;
    bool change_poss = false;
    do {
        change_poss = false;
        ///
        ///Losowanie wartości
        /// 
        new_fruit_poss.x = randomNumber(rozdzielczosc.x);
        new_fruit_poss.y = randomNumber(rozdzielczosc.y);

        ///
        ///Sprawdzenie czy owoc jest w wynaczonym polu
        /// 
        if ((new_fruit_poss.y > rozdzielczosc.y - 80 || new_fruit_poss.y < 80) || (new_fruit_poss.x > rozdzielczosc.x - 80 || new_fruit_poss.x < 80)) {
            change_poss = true;
        }

        ///
        ///Sprawdzanie kolizji jabłka ciałem węża 
        /// 
        for (auto& i : snake) {
            if (i.getShape().getGlobalBounds().intersects(sf::Rect<float>(new_fruit_poss.x, new_fruit_poss.y, 40, 40))) {
                change_poss = true;
                break;
            }
        }

        apple.setPoss(new_fruit_poss);
    } while (change_poss);
    std::cout << "Apple x: " << new_fruit_poss.x << " y: " << new_fruit_poss.y << std::endl;
};