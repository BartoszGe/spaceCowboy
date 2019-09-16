#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "bullet.h"
#include "settings.h"

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
        bool spaceButtonPressed();
        std::vector<Bullet> bullets;
        sf::Time bulletTime {sf::seconds(1/settings::bulletQuantity)};
        sf::Clock bulletClock {sf::Clock()}; 
        bool spaceButton{false};
};

#endif