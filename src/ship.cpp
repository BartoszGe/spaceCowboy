#include "ship.h"

Ship::Ship(float width, float height)
{
    shape.setPosition(width, height);
    shape.setSize({shipWidth, shipHeight});
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(shipWidth/2.f, shipHeight/2.f);
}

void Ship::update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0) {
        velocity.x = -shipVelocity;
        shape.move(this->velocity);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < 800) {
        velocity.x = shipVelocity;
        shape.move(this->velocity);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        
    }
}

void Ship::draw(sf::RenderTarget &target, sf::RenderStates state) const 
{
    target.draw(this->shape, state);
}

float Ship::left() 
{
    return shape.getPosition().x - shape.getSize().x /2.f;
}

float Ship::right() 
{
    return shape.getPosition().x + shape.getSize().x /2.f;
}