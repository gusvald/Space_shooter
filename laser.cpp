//
// Created by Gus on 05.05.2020.
//

#include "laser.h"

laser::laser(sf::Texture *texture,float pos) {//dodaj int mode w zależności od upgrade 1 2 3 strzały

    this->shape.setTexture(*texture);
    this->shape.setScale(0.3f,0.3f);
    this->shape.setPosition(pos + 35, 650);
}
