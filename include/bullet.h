#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

#define ballRadius 10.0f

class Bullet : public sf::Drawable
{
    public:
        Bullet(float x, float y);
        Bullet() = delete;
        ~Bullet() = default;
    private:
    sf::CircleShape shape;
};

#endif