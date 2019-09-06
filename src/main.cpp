#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "ship.h"
#include "asteroid.h"
#include <vector>

bool isIntersecting(Bullet &bullet, Asteroid &asteroid)
{
    return 
        bullet.getTopBound() <= asteroid.getBottomBound() &&
        bullet.getRightBound() >= asteroid.getLeftBound() &&
        bullet.getLeftBound() <= asteroid.getRightBound();
}

bool isCollision(Bullet &bullet, Asteroid &asteroid)
{
    if (isIntersecting(bullet, asteroid)) {
        asteroid.destroy();
        return true;
    }
    return false;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Cowboy");
    window.setFramerateLimit(20);
    Ship ship(400, 550);
    unsigned blockX{2}, blockY{4}, blockWidth{60}, blockHeight{20};
    std::vector<Asteroid> asteroids;
    for (int i = 0; i < blockY; i++) {
        for (int j = 0; j < blockX; j++) {
            asteroids.emplace_back((j+1) * (blockWidth + 10), (i+2) * (blockHeight + 5), blockWidth, blockHeight);
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        ship.update();
        window.draw(ship);

        for (Bullet &bullet: ship.getBullets()) {
            window.draw(bullet); 
            for (Asteroid &asteroid: asteroids) {
                if (isCollision(bullet, asteroid)) {
                    break;
                }
            }
        }
        
        auto iterator = remove_if (begin(asteroids), end(asteroids), [](Asteroid &asteroid) {return asteroid.isDestroyed(); });
        asteroids.erase(iterator, end(asteroids));

        for (Asteroid &asteroid: asteroids) {
            window.draw(asteroid);
        }
        window.display();
    }
    return 0;
}