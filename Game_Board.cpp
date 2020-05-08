//
// Created by Gus on 05.05.2020.
//

#include <iostream>
#include "Game_Board.h"

Game_Board::Game_Board() {
    spaceship player(&space.shipTex);
}

void Game_Board::Events(spaceship &player, const sf::Event &event) {

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
        if (timer >= 35) {

            if (laser_level == 0) {
                player.lasers.emplace_back(&space.laserTex, player.shape.getPosition().x);
            } else if (laser_level == 1) {
                player.lasers.emplace_back(&space.laserTex, player.shape.getPosition().x + 12);
                player.lasers.emplace_back(&space.laserTex, player.shape.getPosition().x - 12);

            } else if (laser_level == 2) {
                player.lasers.emplace_back(&space.laserTex, player.shape.getPosition().x);
                player.lasers.emplace_back(&space.laserTex, player.shape.getPosition().x - 20);
                player.lasers.emplace_back(&space.laserTex, player.shape.getPosition().x + 20);

            } else if (laser_level == 3) {
                player.lasers.emplace_back(&space.laserTex1, player.shape.getPosition().x);
            } else if (laser_level == 4) {
                player.lasers.emplace_back(&space.laserTex1, player.shape.getPosition().x - 30);
                player.lasers.emplace_back(&space.laserTex1, player.shape.getPosition().x + 35);
            } else if (laser_level >= 5) {
                player.lasers.emplace_back(&space.laserTex1, player.shape.getPosition().x - 40);
                player.lasers.emplace_back(&space.laserTex1, player.shape.getPosition().x + 45);
                player.lasers.emplace_back(&space.laserTex1, player.shape.getPosition().x);
            }

            timer = 0;

        }
    }
}

void Game_Board::Logic(sf::RenderWindow &win, spaceship &player) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player.shape.move(-7.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player.shape.move(7.f, 0.f);

    space.ScoreInfo.setString("Score " + std::to_string(player.get_Score()));
    space.LifeInfo.setString("Life " + std::to_string(player.get_HP()) + "  max" + "20");

    for (unsigned int i = 0; i < player.lasers.size(); i++) {
        if (player.lasers[i].shape.getPosition().y < 0) {
            player.lasers.erase(player.lasers.begin() + i);
            break;
        }

        player.lasers[i].shape.move(0.f, -5.f);

        for (unsigned int g = 0; g < space.objects.size(); g++) {
            if (player.lasers[i].shape.getGlobalBounds().intersects(space.objects[g].shape.getGlobalBounds())) {
                if (laser_level >= 3) { space.objects[i].HP = 0; }
                else space.objects[i].HP--;
                if (space.objects[i].HP <= 0) {
                    space.objects.erase(space.objects.begin() + g);
                    player.add_score();
                }

                player.lasers.erase(player.lasers.begin() + i);
                break;

            }

        }

    }

    if (player.shape.getPosition().x <= 0) {
        player.shape.setPosition(0.f, player.shape.getPosition().y);
    }

    if (player.shape.getPosition().x >= win.getSize().x - player.shape.getGlobalBounds().width) {
        player.shape.setPosition(win.getSize().x - player.shape.getGlobalBounds().width,
                                 player.shape.getPosition().y);
    }

    if (timer < 35) { timer++; }

    if (timer1 < 30)
        timer1++;

    if (timer1 >= 30) {
        int random_tex = rand() % 3;
        if (random_tex == 0) { space.objects.emplace_back(&space.enemyTex, win.getSize(), false); }
        if (random_tex == 1) { space.objects.emplace_back(&space.enemy1Tex, win.getSize(), false); }
        if (random_tex == 2) { space.objects.emplace_back(&space.enemy2Tex, win.getSize(), false); }
        timer1 = 0;
    }

    if (clk.getElapsedTime().asSeconds() > 10) {
        space.objects.emplace_back(&space.specialTex, win.getSize(), true);
        clk.restart();
    }

    for (unsigned int i = 0; i < space.objects.size(); i++) {

        if (space.objects[i].special) { space.objects[i].shape.move(0.f, 5.f); }
        else
            space.objects[i].shape.move(0.f, 3.f);


        if (space.objects[i].shape.getPosition().y >=
            win.getSize().y - space.objects[i].shape.getGlobalBounds().height) {
            space.objects.erase(space.objects.begin() + i);
            player.add_score1();
        }


        if (space.objects[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds())) {
            if (space.objects[i].special) {
                laser_level++;
                player.add_score2();
            } else { player.decrease_HP(); }

            space.objects.erase(space.objects.begin() + i);
        }
    }
}

void Game_Board::DrawingGame(sf::RenderWindow &win, spaceship &player) {
    win.draw(player.shape);
    for (unsigned int i = 0; i < player.lasers.size(); i++) {
        win.draw(player.lasers[i].shape);
    }

    for (unsigned int i = 0; i < space.objects.size(); i++) {
        win.draw(space.objects[i].shape);
    }

    win.draw(space.LifeInfo);
    win.draw(space.ScoreInfo);

    if (player.isGameOver()) {
        win.draw(space.GameOver);
    }
}

void Game_Board::RestartGame(int &laser_level, int &timer, int &timer1, spaceship &player) {
    laser_level = 0;
    timer = 35;
    timer1 = -150;
    space.objects.clear();
    player.resetHP();
    player.resetGameOver();
    player.resetSCORE();
    player.resetLasers();
}









