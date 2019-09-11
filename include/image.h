#ifndef IMAGE_H
#define IMAGE_H

#include <SFML/Graphics.hpp>

class Image
{
    public:
        Image(float x, float y, float width, float height)
        {
            sf::Texture texture;
            texture.loadFromFile("images/rocket_ship.png");
            this->sprite = sf::Sprite(texture);
            sprite.setPosition({100, 100});
        }

        sf::Sprite &getSprite()
        {
            return sprite;
        }

        Image() = default;
        ~Image() = default;
    private:
        sf::Sprite sprite ;
};

#endif