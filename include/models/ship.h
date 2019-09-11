#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "bullet.h"


#define shipVelocity 6.0f
class Ship : public Model
{
    public:
        Ship(float x, float y, float width, float height, float velocity) : Model(x, y, width, height, velocity) {};
        Ship() = default;
        ~Ship() = default;
        void update();
        std::vector<Bullet> &getBullets();
    
    private:
        bool spaceButton{false};
        bool spaceButtonPressed();
        std::vector<Bullet> bullets;
};

#endif