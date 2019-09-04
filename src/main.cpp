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

        for(size_t idx = 0; idx < ship.getBullets().size(); idx++) {
            window.draw(ship.getBullets().at(idx)); 
            // printf("bullets idx: %d,  %d \n", (int)idx, (int)ship.getBullets().at(idx).getPosition().y);
        }
        
        window.display();
    }
    return 0;
}