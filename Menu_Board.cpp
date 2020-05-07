//
// Created by Gus on 05.05.2020.
//

#include "Menu_Board.h"
#include "Play_game.h"

Menu_Board::Menu_Board() {

Selected = 0;
}

void Menu_Board::DrawMenu() {
    sf::RenderWindow win(sf::VideoMode(space.get_width(), space.get_height()), "Jupiter");
    win.setActive(true);
    win.setKeyRepeatEnabled(false);
    win.setVerticalSyncEnabled(true);

    Play_game play;

    while (win.isOpen()) {
        sf::Event event{};

        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed((sf::Keyboard::Escape)))) {
                win.close();
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up) {
                moveUP();
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down) {
                moveDOWN();
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {

                if (GetSelected() == 0) {
                    play.playing();
                    win.close();
                }

                if (GetSelected() == 1) {
                    win.close();
                }

                if (GetSelected() == 2) {
                    win.close();
                }
            }
        }


        win.clear(sf::Color(0, 0, 0));
        for (const auto &i : space.Menu) { win.draw(i); }
        win.display();
    }
}

void Menu_Board::moveUP() {
    if (Selected - 1 >= -1) {
        space.Menu[Selected].setFillColor(sf::Color::White);
        Selected--;
        if (Selected == -1) { Selected = 2; }
        space.Menu[Selected].setFillColor(sf::Color::Red);
    }
}

void Menu_Board::moveDOWN() {
    if (Selected + 1 <= 3) {
        space.Menu[Selected].setFillColor(sf::Color::White);
        Selected++;
        if (Selected == 3) { Selected = 0; }
        space.Menu[Selected].setFillColor(sf::Color::Red);
    }
}

int Menu_Board::GetSelected() const {
    return Selected;
}






