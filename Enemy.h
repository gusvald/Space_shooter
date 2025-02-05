//
// Created by Gus on 05.05.2020.
//

#ifndef SPACESHOOTER_ENEMY_H
#define SPACESHOOTER_ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy {
    int HP;
    int HP_max;
    bool special = false;
    sf::Texture *texture;
public:
    sf::Sprite shape;

    Enemy(sf::Texture *texture, sf::Vector2<unsigned int> pos, bool special);

    int getHP();

    void decreaseHP();

    void setlowestHP();

    bool getSpecial();
};


#endif //SPACESHOOTER_ENEMY_H
