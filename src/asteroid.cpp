#include "asteroid.h"

Asteroid::Asteroid(float x, float y, float width, float height)
{
    shape.setPosition(x, y);
    shape.setSize({width, height});
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(width, height);
}

sf::Vector2f Asteroid::getPosition()
{
    return shape.getPosition();
}

float Asteroid::getBottomBound()
{
    return this->shape.getPosition().y + shape.getSize().y /2.f;
}

bool Asteroid::isDestroyed()
{
    return this->destroyed;
}

void Asteroid::destroy()
{
    this->destroyed = true;
}

sf::Vector2f Asteroid::getSize()
{
    return this->shape.getSize();
}
