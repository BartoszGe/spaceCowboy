#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include "model.h"
#include "modelSettings.h"
#include "physics.h"

class Asteroid : public Model
{
    public:
        Asteroid(sf::Texture &texture) : Model
        (
            ModelSettings
            {
                Physics::createRandom(),
                -30.f,
                0.1f,
                0.1f,
                1.f
            },
            texture
        ) {};
};  
#endif