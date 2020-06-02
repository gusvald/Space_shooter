//
// Created by Gus on 05.05.2020.
//

#include "Enemy.h"

#define maxvalue 4
#define minvalue 1

Enemy::Enemy(sf::Texture *texture, sf::Vector2<unsigned int> pos, bool special) {
    this->special = special;
    this->HP_max = rand() % maxvalue + minvalue;
    this->HP = HP_max;
    this->texture = texture;
    this->shape.setTexture(*texture);
    if (special) { this->shape.setScale(0.15f, 0.15f); }
    else
        this->shape.setScale(0.3f, 0.3f);

    this->shape.setPosition(rand() % (int) (pos.x - this->shape.getGlobalBounds().width), 0);
}

int Enemy::getHP() {
    return HP;
}

void Enemy::decreaseHP() {
    HP--;
}

void Enemy::setlowestHP() {
    HP = 0;
}

bool Enemy::getSpecial() {
    return special;
}
