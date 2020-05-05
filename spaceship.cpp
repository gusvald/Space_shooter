//
// Created by Gus on 05.05.2020.
//

#include "spaceship.h"


spaceship::spaceship(sf::Texture *texture) {
    this->HP_max = 20;
    this->HP = HP_max;
    this->score = 0;
    this-> GameOver = false;
    this->texture = texture;
    this->shape.setTexture(*texture);
    this->shape.setPosition(440,650);
}

void spaceship::decrease_HP() {
HP--;
if(HP == 0)
    GameOver = true;

}

bool spaceship::isGameOver() {
    return GameOver;
}

void spaceship::add_score() {
score = score + 100;
}

void spaceship::add_score1() {
    score = score + 10;
}

void spaceship::add_score2() {
    score = score + 500;
}

int spaceship::get_Score() {
    return score;
}

int spaceship::get_HP() {
    return HP;
}




