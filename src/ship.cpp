#include "ship.h"


Ship::Ship(float x, float y)
{
    shape.setPosition(x, y);
    shape.setSize({shipWidth, shipHeight});
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(shipWidth/2.f, shipHeight/2.f);
}

void Ship::handleSpaceButton()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        if(!spacePressed) {
            bullets.push_back(Bullet(getMiddle(), getTopBound(), 2.f, 2.f));
            // printf("bullets %d \n", (int)bullets.size());
        }
        spacePressed = true;
    } else if (sf::Event::KeyReleased) {
        spacePressed = false;
    }
}

void Ship::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && getLeftBound() > 0) {
        velocity.x = -shipVelocity;
        shape.move(this->velocity);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && getRightBound() < 800) {
        velocity.x = shipVelocity;
        shape.move(this->velocity);
    }
    
    handleSpaceButton();

    for (Bullet &bullet: bullets) {
        bullet.update();
    }
}

void Ship::draw(sf::RenderTarget &target, sf::RenderStates state) const 
{
    target.draw(this->shape, state);
}

std::vector<Bullet> &Ship::getBullets()
{
    return this->bullets;
}

float Ship::getTopBound()
{
    return this->shape.getPosition().y - shape.getSize().y /2.f;
}

float Ship::getMiddle()
{
    return this->shape.getPosition().x;
}

float Ship::getLeftBound() 
{
    return this->shape.getPosition().x - shape.getSize().x /2.f;
}

float Ship::getRightBound() 
{
    return this->shape.getPosition().x + shape.getSize().x /2.f;
}
