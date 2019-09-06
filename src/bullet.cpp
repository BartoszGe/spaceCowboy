#include "bullet.h"

Bullet::Bullet(float x, float y)
{
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
    shape.setSize(sf::Vector2f(bulletWidth, bulletHeight));
}

void Bullet::update()
{
    // printf("bullets %d velocity.y %d\n", (int)getPosition().y, (int)this->velocity.y);
    shape.move(this->velocity);
}

void Bullet::draw(sf::RenderTarget &target, sf::RenderStates state) const 
{
    target.draw(this->shape, state);
}

sf::Vector2f Bullet::getPosition()
{
    return shape.getPosition();
}

float Bullet::getTopBound()
{
    return this->shape.getPosition().y - shape.getSize().y /2.f;
}

float Bullet::getLeftBound() 
{
    return this->shape.getPosition().x - shape.getSize().x /2.f;
}

float Bullet::getRightBound() 
{
    return this->shape.getPosition().x + shape.getSize().x /2.f;
}