#include "bullet.h"

Bullet::Bullet(float width, float height)
{
    shape.setPosition(width, height);
    shape.setFillColor(sf::Color::White);
    shape.setSize(sf::Vector2f(bulletWidth, bulletHeight));
}

void Bullet::update()
{
    shape.move(this->velocity);
}

sf::Vector2f Bullet::getPosition()
{
    return shape.getPosition();
}

void Bullet::draw(sf::RenderTarget &target, sf::RenderStates state) const 
{
    target.draw(this->shape, state);
}