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


    Spaceship player(&space.shipTex);
    MenuBoard menu;
    GameBoard play;
    ResultsBoard result;


    while (win.isOpen()) {

        page = menu.getPage();

        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed || page == 2) {
                win.close();
                continue;
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

            if (page == 0) {
                play.Events(player, event);
            }

            if (page == 3) {
                menu.Events(event);
            }
        }

        if (!player.isGameOver() && page == 0) {
            play.Logic(win, player);
            if (play.clk3.getElapsedTime().asMilliseconds() > 120) {
                play.explosions.clear();
                play.clk3.restart();
            }

        } else if (player.isGameOver() && !IsAlreadySaved) {
            result.saveScore(player.get_Score());
            IsAlreadySaved = true;
        }


        win.clear(sf::Color(0, 0, 0));
        if (page == 0) {
            play.DrawingGame(win, player);
        }

        if (page == 1) {
            result.LoadResults();
            result.DrawResults(win);
        }

        if (page == 3) {
            menu.DrawingMenu(win);
        }

        win.display();
    }
}



