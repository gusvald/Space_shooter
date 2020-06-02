//
// Created by Gus on 05.05.2020.
//

#include "MenuBoard.h"

MenuBoard::MenuBoard() {
    this->shape.setTexture(space.Game_logo);
    this->shape.setPosition(600, 200);
    this->shape.setScale(0.7f, 0.7f);

    this->logo.setTexture(space.Game_sigTex);
    this->logo.setPosition(40, 60);
    this->logo.setScale(0.5f, 0.5f);
    Selected = 0;
}

void MenuBoard::moveUP() {
    if (Selected - 1 >= -1) {
        space.Menu[Selected].setFillColor(sf::Color::White);
        Selected--;
        if (Selected == -1) { Selected = 2; }
        space.Menu[Selected].setFillColor(sf::Color::Cyan);
    }
}

void MenuBoard::moveDOWN() {
    if (Selected + 1 <= 3) {
        space.Menu[Selected].setFillColor(sf::Color::White);
        Selected++;
        if (Selected == 3) { Selected = 0; }
        space.Menu[Selected].setFillColor(sf::Color::Cyan);
    }
}

int MenuBoard::GetSelected() const {
    return Selected;
}

void MenuBoard::Events(const sf::Event &event) {
    DrawingGame game;

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

void MenuBoard::DrawingMenu(sf::RenderWindow &win) {
    for (const auto &i : space.Menu) { win.draw(i); }
    win.draw(shape);
    win.draw(logo);
}

int MenuBoard::getPage() {
    return Page;
}

void MenuBoard::setPage3() {
    Page = 3;
}






