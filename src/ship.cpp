#include "ship.h"


Ship::Ship(float x, float y)
{
    shape.setPosition(x, y);
    shape.setSize({shipWidth, shipHeight});
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(shipWidth/2.f, shipHeight/2.f);
    spacePressed = false;
}

void Ship::handleSpaceButton()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        if(!spacePressed) {
            bullets.push_back(Bullet(getMiddlePosition(), getTopPosition()));
            // printf("bullets %d \n", (int)bullets.size());
        }
        spacePressed = true;
    } else if(sf::Event::KeyReleased) {
        spacePressed = false;
    }
}

void Ship::update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && getLeftPosition() > 0) {
        velocity.x = -shipVelocity;
        shape.move(this->velocity);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && getRightPosition() < 800) {
        velocity.x = shipVelocity;
        shape.move(this->velocity);
    }
    
    handleSpaceButton();
    for(size_t idx = 0; idx < bullets.size(); idx++) {
        bullets.at(idx).update();
    }
}

void Ship::draw(sf::RenderTarget &target, sf::RenderStates state) const 
{
    target.draw(this->shape, state);
}

std::vector<Bullet> Ship::getBullets()
{
    return this->bullets;
}

float Ship::getTopPosition()
{
    return this->shape.getPosition().y - shape.getSize().y /2.f;
}

float Ship::getMiddlePosition()
{
    return this->shape.getPosition().x;
}

float Ship::getLeftPosition() 
{
    return this->shape.getPosition().x - shape.getSize().x /2.f;
}

float Ship::getRightPosition() 
{
    return this->shape.getPosition().x + shape.getSize().x /2.f;
}

