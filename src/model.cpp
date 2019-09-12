#include "model.h"

Model::Model(float x, float y, float width, float height, float velocity)
{
    shape.setPosition(x, y);
    shape.setSize({width, height});
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(width / 2.f, height / 2.f);
    setVelocity(velocity);
}

Model::Model(ModelSettings model)
{
    shape.setPosition(model.x, model.y);
    shape.setSize({model.width, model.height});
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(model.width / 2.f, model.height / 2.f);
    setVelocity(model.velocity);
}

Model::Model(ModelSettings model, sf::Texture &texture)
{
    sprite = sf::Sprite(texture);
    sprite.value().setPosition(model.x, model.y);
    sprite.value().setScale({model.width, model.height});
    sprite.value().setOrigin(model.width / 2.f, model.height / 2.f);
    setVelocity(model.velocity);
}

void Model::update()
{
    if(sprite.has_value()) {
        sprite.value().move(this->velocity);
    } else {
        shape.move(this->velocity);
    }
}

void Model::setVelocity(float velocity)
{
    this->velocity = {0, velocity};
}

sf::Vector2f Model::getPosition()
{
    if(sprite.has_value()) {
        sprite.value().getPosition();
    } else {
        return shape.getPosition();
    }
}

float Model::getTopBound()
{
    if(sprite.has_value()) {
        return this->sprite.value().getGlobalBounds().top;
    } else {
       return this->shape.getPosition().y - shape.getSize().y /2.f;
    }
}

float Model::getLeftBound() 
{
    if(sprite.has_value()) {
        return this->sprite.value().getGlobalBounds().left;
        
    } else {
        return this->shape.getPosition().x - shape.getSize().x /2.f;
    }
}

float Model::getRightBound() 
{
    if(sprite.has_value()) {
        return this->sprite.value().getGlobalBounds().left + this->sprite.value().getGlobalBounds().height;
        
    } else {
        return this->shape.getPosition().x + shape.getSize().x /2.f;
    }
    
}

float Model::getBottomBound()
{
    if(sprite.has_value()) {
        return this->sprite.value().getGlobalBounds().top + this->sprite.value().getGlobalBounds().height;
        
    } else {
        return this->shape.getPosition().y + shape.getSize().y /2.f;
    }
    
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
    if(sprite.has_value()) {
        target.draw(sprite.value(), state);
    } else {
        target.draw(this->shape, state);
    }
}

