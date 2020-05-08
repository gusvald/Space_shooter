//
// Created by Gus on 05.05.2020.
//

#include "Menu_Board.h"

Menu_Board::Menu_Board() {
    this->shape.setTexture(space.Game_logo);
    this->shape.setPosition(550, 130);
    this->shape.setScale(0.7f, 0.7f);
    Selected = 0;
}

void Menu_Board::moveUP() {
    if (Selected - 1 >= -1) {
        space.Menu[Selected].setFillColor(sf::Color::White);
        Selected--;
        if (Selected == -1) { Selected = 2; }
        space.Menu[Selected].setFillColor(sf::Color::Cyan);
    }
}

void Menu_Board::moveDOWN() {
    if (Selected + 1 <= 3) {
        space.Menu[Selected].setFillColor(sf::Color::White);
        Selected++;
        if (Selected == 3) { Selected = 0; }
        space.Menu[Selected].setFillColor(sf::Color::Cyan);
    }
}

int Menu_Board::GetSelected() const {
    return Selected;
}

void Menu_Board::Events(const sf::Event &event) {
    Drawing_game game;

    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up) {
        moveUP();
    }

    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down) {
        moveDOWN();
    }

    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {

        if (GetSelected() == 0) {
            Page = 0;
        }

        if (GetSelected() == 1) {
            Page = 1;
        }

        if (GetSelected() == 2) {
            Page = 2;
        }
    }
}

void Menu_Board::DrawingMenu(sf::RenderWindow &win) {
    for (const auto &i : space.Menu) { win.draw(i); }
    win.draw(shape);
}

int Menu_Board::getPage() {
    return Page;
}

void Menu_Board::setPage3() {
    Page = 3;
}






