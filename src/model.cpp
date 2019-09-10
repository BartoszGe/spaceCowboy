#include "model.h"

Model::Model(float x, float y, float width, float height)
{
    shape.setPosition(x, y);
    shape.setSize({width, height});
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(width / 2.f, height / 2.f);
}

void Model::update()
{
    shape.move(this->velocity);
}

void Model::setVelocity(float velocity)
{
    this->velocity = {0, velocity};
}

sf::Vector2f Model::getPosition()
{
    return shape.getPosition();
}

float Model::getTopBound()
{
    return this->shape.getPosition().y - shape.getSize().y /2.f;
}

float Model::getLeftBound() 
{
    return this->shape.getPosition().x - shape.getSize().x /2.f;
}

float Model::getRightBound() 
{
    return this->shape.getPosition().x + shape.getSize().x /2.f;
}

float Model::getBottomBound()
{
    return this->shape.getPosition().y + shape.getSize().y /2.f;
}

bool Model::isDestroyed()
{
    return this->destroyed;
}

void Model::destroy()
{
    this->destroyed = true;
}

void Model::draw(sf::RenderTarget &target, sf::RenderStates state) const 
{
    target.draw(this->shape, state);
}

