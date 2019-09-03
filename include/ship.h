#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>

#define shipWidth 80.0f
#define shipHeight 20.0f
#define shipVelocity 6.0f

class Ship : public sf::Drawable
{
    public:
        Ship(float width, float height);
        Ship() = delete;
        ~Ship() = default;
        void update();
    
    private:
        void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
        sf::RectangleShape shape;
        sf::Vector2f velocity {shipVelocity, 0.f};
        float left();
        float right();
};

#endif