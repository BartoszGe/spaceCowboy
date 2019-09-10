#ifndef PHYSICS_H
#define PHYSICS_H

#include <SFML/Graphics.hpp>
#include "model.h"
#include "asteroid.h"
#include "bullet.h"
#include "ship.h"

class Physics
{
    private:
        Physics() {}
        Physics(const Physics&);
        void operator=(Physics const&);
        
    public:
        static Physics &getInstance()
        {
            static Physics Physics;
            return Physics;
        }

        bool isIntersecting(Model &model1, Model &model2)
        {
            return 
            model1.getTopBound() <= model2.getBottomBound() &&
            model1.getBottomBound() >= model2.getTopBound() &&
            model1.getRightBound() >= model2.getLeftBound() &&
            model1.getLeftBound() <= model2.getRightBound();
        }

        void checkCollision(std::vector<Asteroid> &asteroids, std::vector<Bullet> &bullets)
        {
            for (Asteroid &asteroid: asteroids) {
                for (Bullet &bullet: bullets) {
                    if (isCollision(asteroid, bullet)) {
                        asteroid.destroy();
                        bullet.destroy();
                    }
                }   
            }
        }

        void checkCollision(std::vector<Asteroid> &asteroids, Ship &ship)
        {
            for (Asteroid &asteroid: asteroids) {
                if (Physics::getInstance().isCollision(asteroid, ship)) {
                    asteroid.destroy();
                    ship.destroy();
                    break;
                }
            }
        }

        bool isCollision(Model &model1, Model &model2)
        {
            if (isIntersecting(model1, model2)) {
                return true;
            }
            return false;
        }

};

#endif