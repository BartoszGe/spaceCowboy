#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "bullet.h"


#define shipVelocity 6.0f
class Ship : public Model
{
    public:
        Ship(sf::Texture &texture) : Model (
            ModelSettings {
                400,
                500,
                1,
                1,
                6.f
            },
            texture
        ) {};
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