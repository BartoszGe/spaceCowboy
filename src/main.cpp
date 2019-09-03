#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "ship.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Cowboy");
    window.setFramerateLimit(60);
    Bullet bullet(400, 300);
    Ship ship(400, 550);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        bullet.update();
        ship.update();
        window.draw(bullet);
        window.draw(ship);
        window.display();
    }

    return 0;
}