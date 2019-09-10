#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "bullet.h"

#define shipWidth 80.0f
#define shipHeight 20.0f
#define shipVelocity 6.0f

class Ship : public sf::Drawable
{
    public:
        Ship(float x, float y);
        Ship() {}
        ~Ship() = default;
        void update();
        std::vector<Bullet> &getBullets();
        Ship& operator=(const Ship& ship) { return *this; }
        float getTopBound();
        float getMiddle();
        float getLeftBound();
        float getRightBound();
    
    private:
        void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
        sf::RectangleShape shape;
        sf::Vector2f velocity {shipVelocity, 0.f};
        sf::RenderWindow window;

        bool spacePressed{false};
        void handleSpaceButton();
        std::vector<Bullet> bullets;
};

#endif