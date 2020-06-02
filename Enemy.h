//
// Created by Gus on 05.05.2020.
//

#ifndef SPACESHOOTER_ENEMY_H
#define SPACESHOOTER_ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy {
public:
    int HP;
    int HP_max;
    bool special = false;
    sf::Sprite shape;
    sf::Texture *texture;

    Enemy(sf::Texture *texture, sf::Vector2<unsigned int> pos, bool special);


};


#endif //SPACESHOOTER_ENEMY_H
