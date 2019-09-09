#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include "model.h"

class Asteroid : public Model
{
    public:
        Asteroid(float x, float y, float width, float height) : Model(x, y, width, height) {};
        Asteroid() = delete;
        ~Asteroid() = default;
};

#endif