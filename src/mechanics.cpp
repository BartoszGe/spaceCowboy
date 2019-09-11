#include "mechanics.h"

Mechanics::Mechanics(Ship &ship)
{   
    this->ship = &ship;
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
void updateVector(std::vector<T> &models)
{
    auto iterator = remove_if(begin(models), end(models), [](Model &model) {return model.isDestroyed(); });
    models.erase(iterator, end(models));
}

void Mechanics::update()
{
    // printf("asteroids: %p asteroids :%d, asteroidTime %d\n", &stars, (int)stars.size(), (int)starTime.asMilliseconds());
    createSpaceObjects(asteroids, asteroidTime, asteroidClock);
    createSpaceObjects(stars, starTime, starClock);
    updateVector(asteroids);
    updateVector(stars);
    updateVector(*bullets);
    Physics::checkCollision(asteroids, *bullets);
    Physics::checkCollision(asteroids, *ship);
    Physics::checkOutOfBounds(asteroids);
    Physics::checkOutOfBounds(stars);
    Physics::checkOutOfBounds(*bullets);

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