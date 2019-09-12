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
        move(velocity);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && getRightBound() < 800) {
        velocity = {shipVelocity, 0};
        move(velocity);
    }
    
    if(spaceButtonPressed()) {
            bullets.push_back(Bullet(getPosition().x, getTopBound(), 2.f, 2.f, -6.f));
            printf("bullet : %d\n", (int)getPosition().x);
    }
}

std::vector<Bullet> &Ship::getBullets()
{
    return this->bullets;
}