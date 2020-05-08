//
// Created by Gus on 05.05.2020.
//

#ifndef SPACESHOOTER_GAME_BOARD_H
#define SPACESHOOTER_GAME_BOARD_H

#include <SFML/Graphics.hpp>
#include "textures_in.h"
#include "spaceship.h"
#include "Menu_Board.h"


class Game_Board {
    textures_in space;
public:
    sf::Clock clk, clk1, clk2, clk3;
    int laser_level = 0;

    Game_Board();

    void Events(spaceship &player, const sf::Event &event);

    void Logic(sf::RenderWindow &win, spaceship &player);

    void DrawingGame(sf::RenderWindow &win, spaceship &player);

    void RestartGame(spaceship &player);

    std::vector<sf::Sprite> explosions;

};


#endif //SPACESHOOTER_GAME_BOARD_H
