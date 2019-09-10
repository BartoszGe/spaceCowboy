#include "ship.h"

bool Ship::spaceButtonPressed()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        if(!spaceButton) {
            spaceButton = true;
            return true;
        }
    } else if (sf::Event::KeyReleased) {
        spaceButton = false;
    }
    return false;
}

void Ship::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && getLeftBound() > 0) {
        velocity = {-shipVelocity, 0};
        shape.move(this->velocity);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && getRightBound() < 800) {
        velocity = {shipVelocity, 0};
        shape.move(this->velocity);
    }
    
    if(spaceButtonPressed()) {
        bullets.push_back(Bullet(getPosition().x, getTopBound(), 2.f, 2.f));
    }

    for (Bullet &bullet: bullets) {
        bullet.update();
    }
}

std::vector<Bullet> &Ship::getBullets()
{
    return this->bullets;
}

