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

sf::Vector2f Bullet::getPosition()
{
    return shape.getPosition();
}

void Bullet::draw(sf::RenderTarget &target, sf::RenderStates state) const 
{
    target.draw(this->shape, state);
}