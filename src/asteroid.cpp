#include "asteroid.h"

Asteroid::Asteroid(float x, float y, float width, float height)
{
    shape.setPosition(x, y);
    shape.setSize({width, height});
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(width / 2.f, height / 2.f);
}

sf::Vector2f Asteroid::getPosition()
{
    return shape.getPosition();
}

float Asteroid::getBottomBound()
{
    return this->shape.getPosition().y + shape.getSize().y /2.f;
}

float Asteroid::getLeftBound() 
{
    return this->shape.getPosition().x - shape.getSize().x /2.f;
}

float Asteroid::getRightBound() 
{
    return this->shape.getPosition().x + shape.getSize().x /2.f;
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

void Asteroid::draw(sf::RenderTarget &target, sf::RenderStates state) const 
{
    target.draw(this->shape, state);
}