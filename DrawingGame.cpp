//
// Created by Gus on 07.05.2020.
//


#include "DrawingGame.h"


DrawingGame::DrawingGame() {
}

void DrawingGame::drawing() {
    sf::RenderWindow win(sf::VideoMode(space.get_width(), space.get_height()), "Jupiter",
                         sf::Style::Titlebar | sf::Style::Close);
    win.setActive(true);
    win.setKeyRepeatEnabled(false);
    win.setVerticalSyncEnabled(true);
    win.setFramerateLimit(60);

    sf::Event event{};


    Spaceship player(&space.textures[0]);
    MenuBoard menu;
    GameBoard play;
    ResultsBoard result;


    while (win.isOpen()) {

        page = menu.getPage();

        while (win.pollEvent(event)) {
            events(event, win, player, menu, play);
        }

        savinglogic(win, play, player, result);

        win.clear(sf::Color(0, 0, 0));
        if (page == Play) {
            play.DrawingGame(win, player);
        }

        if (page == Result) {
            result.LoadResults();
            result.DrawResults(win);
        }

        if (page == Menu) {
            menu.DrawingMenu(win);
        }

        win.display();
    }
}

void DrawingGame::events(sf::Event &event, sf::RenderWindow &win, Spaceship &player, MenuBoard &menu, GameBoard &play) {
    if (event.type == sf::Event::Closed || page == Exit) {
        win.close();
    }

    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::R) {
        play.RestartGame(player);
        IsAlreadySaved = false;
    }

    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::M) {
        menu.setPage3();
        if (player.isGameOver()) {
            play.RestartGame(player);
            IsAlreadySaved = false;
        }
    }

    if (page == Play) {
        play.Events(player, event);
    }

    if (page == Menu) {
        menu.Events(event);
    }
}

void DrawingGame::savinglogic(sf::RenderWindow &win, GameBoard &play, Spaceship &player, ResultsBoard &result) {
    if (!player.isGameOver() && page == Play) {
        play.Logic(win, player);
        if (play.clk3.getElapsedTime().asMilliseconds() > 120) {
            play.explosions.clear();
            play.clk3.restart();
        }

    } else if (player.isGameOver() && !IsAlreadySaved) {
        result.saveScore(player.get_Score());
        IsAlreadySaved = true;
    }
}





