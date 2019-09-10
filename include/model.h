#ifndef MODEL_H
#define MODEL_H

#include <SFML/Graphics.hpp>

class Model : public sf::Drawable
{
    public:
        Model(float x, float y, float width, float height);
        Model() = default;
        ~Model() = default;
        void update();

        void setVelocity(float velocity);

        sf::Vector2f getPosition();
        float getTopBound();
        float getLeftBound();
        float getRightBound();
        float getBottomBound();

        bool isDestroyed();
        void destroy();
        sf::Vector2f getSize();

    protected:
        void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
        sf::RectangleShape shape;
        sf::Vector2f velocity;
        bool destroyed{false};
};

#endif