//
// Created by Gus on 05.05.2020.
//

#ifndef SPACESHOOTER_LASER_H
#define SPACESHOOTER_LASER_H
#include<SFML/Graphics.hpp>





class laser {
public:
    laser(sf::Texture *texture, float pos);
    sf::Sprite shape;
};


#endif //SPACESHOOTER_LASER_H
