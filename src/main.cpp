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
    Ship ship(400, 550, 70, 20, 6.0f);
    Mechanics mechanics(ship);

    std::vector<Asteroid> *asteroids = &mechanics.getAsteroids();
    std::vector<Star> *stars = &mechanics.getStars();
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

        for (Asteroid &asteroid: *asteroids) {
            asteroid.update();
            window.draw(asteroid);
        }
        
        for (Star &star: *stars) {
            star.update();
            window.draw(star);
        }

        for (Bullet &bullet: *bullets) {
            bullet.update();
            window.draw(bullet);
        }

        window.display();
    }
    return 0;
}