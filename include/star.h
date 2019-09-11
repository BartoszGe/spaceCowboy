#ifndef START_H
#define START_H

#include <SFML/Graphics.hpp>
#include "model.h"
#include "physics.h"


class Star : public Model
{
    public:
        Star() : Model(Physics::createRandom(), -1, 1, 1, 6.f) {};
};

#endif