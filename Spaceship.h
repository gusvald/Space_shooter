//
// Created by Gus on 05.05.2020.
//

#ifndef TEST_SFML_SPACESHIP_H
#define TEST_SFML_SPACESHIP_H

#include<SFML/Graphics.hpp>
#include <fstream>
#include "vector"
#include "Laser.h"

class Spaceship {

    int HP_max;
    int HP;
    bool GameOver;
    int score;
    int ScoreBoard[11];
public:
    std::vector<Laser> lasers;
    sf::Sprite shape;
    sf::Texture *texture;

    explicit Spaceship(sf::Texture *texture);

    void decrease_HP();

    int get_HP();

    int get_Score();

    bool isGameOver();

    void add_score();

    void add_score1();

    void add_score2();

    void Safe_Score();

    void resetHP();

    void resetSCORE();

    void resetGameOver();

    void resetLasers();

    std::fstream file;
    std::string line;

};


#endif //TEST_SFML_SPACESHIP_H
