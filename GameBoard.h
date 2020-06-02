//
// Created by Gus on 05.05.2020.
//

#ifndef SPACESHOOTER_GAMEBOARD_H
#define SPACESHOOTER_GAMEBOARD_H

#include <SFML/Graphics.hpp>
#include "TexturesIn.h"
#include "Spaceship.h"
#include "MenuBoard.h"


class GameBoard {
    TexturesIn space;
    int laser_level = 0;
public:
    sf::Clock clk, clk1, clk2, clk3;

    GameBoard();

    void Events(Spaceship &player, const sf::Event &event);

    void Logic(sf::RenderWindow &win, Spaceship &player);

    void DrawingGame(sf::RenderWindow &win, Spaceship &player);

    void RestartGame(Spaceship &player);

    void movement(Spaceship &player);

    void info(Spaceship &player);

    void lasers(Spaceship &player);

    void playerPos(Spaceship &player, sf::RenderWindow &win);

    void asteroids(sf::Clock &clk, sf::Clock &clk2, sf::RenderWindow &win);

    void colisions(sf::RenderWindow &win, Spaceship &player);

    std::vector<sf::Sprite> explosions;

};


#endif //SPACESHOOTER_GAMEBOARD_H
