#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include "model.h"
#include "physics.h"

class Asteroid : public Model
{
    public:
        Asteroid() : Model(Physics::createRandom(), -30, 30, 10, 1.f) {};

};

#endif