#ifndef MECHANICS_H
#define MECHANICS_H

#include <SFML/Graphics.hpp>
#include "ship.h"
#include "model.h"
#include "asteroid.h"
#include "bullet.h"
#include "physics.h"

class Mechanics
{
    public:
        Mechanics(Ship &ship);
        Mechanics() = delete;
        ~Mechanics() = default;
        void update();

        std::vector<Asteroid> &getAsteroids();
        std::vector<Bullet> &getBullets();

    private:
        Ship *ship;
        std::vector<Asteroid> asteroids;
        std::vector<Bullet> *bullets;
};

#endif