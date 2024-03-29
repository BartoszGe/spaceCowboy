#include "mechanics.h"

Mechanics::Mechanics()
{   
    this->shipTexture.loadFromFile("images/rocket_ship128px.png");
    this->asteroidTexture.loadFromFile("images/asteroid64px.png");
    this->ship = Ship(shipTexture);
    this->bullets = &ship.getBullets();
}

template <class T>
void createSpaceObjects(std::vector<T> &models, sf::Time delay, sf::Clock &clock)
{
    if(delay <= clock.getElapsedTime()) {
        T model;
        models.push_back(model);
        clock.restart();
    }
}

template <class T>
void createSpaceObjects(std::vector<T> &models, sf::Texture &texture, sf::Time delay, sf::Clock &clock)
{
    if(delay <= clock.getElapsedTime()) {
        T model(texture);
        models.push_back(model);
        clock.restart();
    }
}

template <class T>
void updateVector(std::vector<T> &models)
{
    auto iterator = remove_if(begin(models), end(models), [](Model &model) {return model.isDestroyed(); });
    models.erase(iterator, end(models));
}

void Mechanics::update()
{
    createSpaceObjects(asteroids, asteroidTexture, asteroidTime, asteroidClock);
    createSpaceObjects(stars, starTime, starClock);
    Physics::checkCollision(asteroids, *bullets);
    Physics::checkCollision(asteroids, ship);
    Physics::checkOutOfBounds(asteroids);
    Physics::checkOutOfBounds(stars);
    Physics::checkOutOfBounds(*bullets);
    updateVector(asteroids);
    updateVector(stars);
    updateVector(*bullets);
}

Ship &Mechanics::getShip()
{
    return ship;
}

std::vector<Asteroid> &Mechanics::getAsteroids()
{
    return asteroids;
}

std::vector<Star> &Mechanics::getStars()
{
    return stars;
}

std::vector<Bullet> &Mechanics::getBullets()
{
    return *bullets;
}