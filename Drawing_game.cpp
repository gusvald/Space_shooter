//
// Created by Gus on 07.05.2020.
//

#include <iostream>
#include "Drawing_game.h"


Drawing_game::Drawing_game() {
}

void Drawing_game::drawing() {
    sf::RenderWindow win(sf::VideoMode(space.get_width(), space.get_height()), "Jupiter");
    win.setActive(true);
    win.setKeyRepeatEnabled(false);
    win.setVerticalSyncEnabled(true);
    sf::Event event{};


    spaceship player(&space.shipTex);
    Menu_Board menu;
    Game_Board play;
    Results_board result;


    while (win.isOpen()) {

        page = menu.getPage();

        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed || page == 2) {
                win.close();
                continue;
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::R) {
                play.RestartGame(play.laser_level, play.timer, play.timer1, player);
                Done = false;
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::M) {
                menu.setPage3();
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
        } else if (player.isGameOver() && !Done) {
            player.Safe_Score();
            Done = true;
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



