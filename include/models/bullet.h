#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "model.h"

class Bullet : public Model
{
    public:
        Bullet(float x, float y, float width, float height, float velocity) : Model(x, y, width, height, velocity) {};
        Bullet() = delete;
        ~Bullet() = default;
};

#endif