#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

#define bulletWidth 2.0f
#define bulletHeight 10.0f
#define bulletVelocity 6.0f

class Bullet : public sf::Drawable
{
    public:
        Bullet(float x, float y);
        Bullet() = delete;
        ~Bullet() = default;
        void update();
        sf::Vector2f getPosition();
        float getTopBound();

    private:
        void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
        sf::RectangleShape shape;
        sf::Vector2f velocity {0, -bulletVelocity};
};

#endif