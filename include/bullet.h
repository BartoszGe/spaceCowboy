#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "model.h"

#define bulletWidth 2.0f
#define bulletHeight 10.0f
#define bulletVelocity 6.0f

class Bullet : public Model
{
    public:
        Bullet(float x, float y, float width, float height) : Model(x, y, width, height) {};
        Bullet() = delete;
        ~Bullet() = default;
};

#endif