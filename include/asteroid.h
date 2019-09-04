#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>

class Asteroid : public sf::Drawable
{
    public:
        Asteroid(float x, float y, float width, float height);
        Asteroid() = delete;
        ~Asteroid() = default;
        void update();
        sf::Vector2f getPosition();
        float getBottomBound();

        bool isDestroyed();
        void destroy();
        sf::Vector2f getSize();

    private:
    // virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
    sf::RectangleShape shape;
    bool destroyed{false};
};

#endif