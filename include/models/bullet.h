#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "model.h"

class Bullet : public Model
{
    public:
        Bullet(ModelSettings bulletSettings) : Model(bulletSettings) {};
        Bullet() = delete;
        ~Bullet() = default;
};

#endif