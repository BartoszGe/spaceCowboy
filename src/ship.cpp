#include "ship.h"

void Ship::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && getLeftBound() > 0) {
        velocity = {-settings::shipVelocity, 0};
        move(velocity);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && getRightBound() < 800) {
        velocity = {settings::shipVelocity, 0};
        move(velocity);
    }
    
    if(spaceButtonPressed()) {
        bullets.push_back( 
            Bullet (
                ModelSettings {
                    getPosition().x,
                    getTopBound(),
                    3.f,
                    3.f,
                    -(settings::bulletVelocity/2000)
                }
            )
        );
    }
}


bool Ship::spaceButtonPressed()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        if(bulletTime <= bulletClock.getElapsedTime() || !spaceButton)  {
            spaceButton = true;
            bulletClock.restart();
            return true;
        }
    }
    else if (sf::Event::KeyReleased) {
        spaceButton = false;
    }
    return false;
}

std::vector<Bullet> &Ship::getBullets()
{
    return this->bullets;
}