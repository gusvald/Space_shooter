//
// Created by Gus on 05.05.2020.
//

#include "Spaceship.h"


Spaceship::Spaceship(sf::Texture *texture) {
    this->HP_max = 20;
    this->HP = HP_max;
    this->score = 0;
    this->GameOver = false;
    this->texture = texture;
    this->shape.setTexture(*texture);
    this->shape.setPosition(440, 650);
}

void Spaceship::decrease_HP() {
    this->HP--;
    if (this->HP == 0)
        GameOver = true;

}

bool Spaceship::isGameOver() {
    return this->GameOver;
}

void Spaceship::add_score() {
    this->score = this->score + 100;
}

void Spaceship::add_score1() {
    this->score = this->score + 10;
}

void Spaceship::add_score2() {
    this->score = this->score + 500;
}

int Spaceship::get_Score() {
    return this->score;
}

int Spaceship::get_HP() {
    return this->HP;
}

void Spaceship::resetHP() {
    this->HP = this->HP_max;
}

void Spaceship::resetSCORE() {
    this->score = 0;
}

void Spaceship::resetGameOver() {
    GameOver = false;
}

void Spaceship::resetLasers() {
    lasers.clear();
}








