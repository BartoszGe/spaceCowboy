#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "ship.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Cowboy");
    window.setFramerateLimit(20);
    Ship ship(400, 550);
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

        for(Bullet bullet: ship.getBullets()) {
            window.draw(bullet); 
        }
        
        window.display();
    }
    return 0;
}