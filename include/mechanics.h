#ifndef MECHANICS_H
#define MECHANICS_H

#include <SFML/Graphics.hpp>
#include "ship.h"
#include "model.h"
#include "asteroid.h"
#include "bullet.h"
#include "star.h"

class Mechanics
{
    public:
        Mechanics(Ship &ship);
        Mechanics() = delete;
        ~Mechanics() = default;
        void update();

        std::vector<Asteroid> &getAsteroids();
        std::vector<Star> &getStars();
        std::vector<Bullet> &getBullets();

    private:
        Ship *ship;

        sf::Texture asteroidTexture;
        std::vector<Asteroid> asteroids;
        std::vector<Star> stars;
        std::vector<Bullet> *bullets;
     
        sf::Time asteroidTime {sf::milliseconds(300)};
        sf::Time starTime {sf::milliseconds(50)};
        sf::Clock asteroidClock {sf::Clock()};
        sf::Clock starClock {sf::Clock()};
};

#endif