#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include "model.h"
#include "modelSettings.h"
#include "physics.h"

class Asteroid : public Model
{
    public:
        Asteroid(sf::Texture &texture) : Model (
            ModelSettings { 
                Physics::createRandom(),
                -100.f,
                1,
                1,
                1.f },
            texture ) {};

        void update()
        {
            if(sprite.has_value()) {
                sprite.value().move(this->velocity);
                sprite.value().rotate(1.f);
            } else {
                shape.move(this->velocity);
            }
        }
};  
#endif