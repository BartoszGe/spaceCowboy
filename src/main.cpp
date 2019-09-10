#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "ship.h"
#include "asteroid.h"
#include <vector>
#include "physics.h"
#include "mechanics.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Cowboy");
    window.setFramerateLimit(60);
    Ship ship(400, 550);
    Mechanics mechanics(ship);
    std::vector<Asteroid> *asteroids = &mechanics.getAsteroids();
    printf("vector main: %p\n", asteroids);

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
            for (Asteroid &asteroid: *asteroids) {
                if (Physics::getInstance().isCollision(bullet, asteroid)) {
                    bullet.destroy();
                    asteroid.destroy();
                    break;
                }
            }
        }
        
        mechanics.update();

        for (Asteroid &asteroid: *asteroids) {
            window.draw(asteroid);
        }
        window.display();
    }
    return 0;
}