//
// Created by Gus on 05.05.2020.
//

#include "enemy.h"

enemy::enemy(sf::Texture *texture, sf::Vector2<unsigned int> pos, bool special) {
    this->special = special;
    this->HP_max = rand() % 4 + 1;
    this->HP = HP_max;
    this->texture = texture;
    this->shape.setTexture(*texture);
    if(special)
    { this-> shape.setScale(0.15f, 0.15f);}
    else
    this-> shape.setScale(0.3f, 0.3f);

    this->shape.setPosition(rand()%(int)(pos.x - this->shape.getGlobalBounds().width) ,0);
}
