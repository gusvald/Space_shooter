//
// Created by Gus on 05.05.2020.
//

#ifndef TEST_SFML_SPACESHIP_H
#define TEST_SFML_SPACESHIP_H
#include<SFML/Graphics.hpp>
#include "vector"
#include "laser.h"

class spaceship {

    int HP_max;
    int HP;
    bool GameOver;
    int score;
public:
    std::vector<laser>lasers;
    sf::Sprite shape;
    sf::Texture *texture;
    spaceship(sf::Texture *texture);
    void decrease_HP();
    int get_HP();
    int get_Score();
    bool isGameOver();
    void add_score();
    void add_score1();
    void add_score2();


};


#endif //TEST_SFML_SPACESHIP_H
