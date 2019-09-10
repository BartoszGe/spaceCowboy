#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "ship.h"
#include "asteroid.h"
#include <vector>
#include "mechanics.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Cowboy");
    window.setFramerateLimit(60);
    Ship ship(400, 550, 70, 20);
    Mechanics mechanics(ship);
    std::vector<Asteroid> *asteroids = &mechanics.getAsteroids();
    std::vector<Bullet> *bullets = &mechanics.getBullets();

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

        mechanics.update();

        for (Bullet &bullet: *bullets) {
            window.draw(bullet);
        }

        for (Asteroid &asteroid: *asteroids) {
            window.draw(asteroid);
        }
        
        window.display();
    }
    return 0;
}