#include "mechanics.h"
#include <random>

int createRandom()
{
    std::random_device random_device;
    std::mt19937 random_engine(random_device());
    std::uniform_int_distribution<int> distribution_1_100(50, 750);
    return distribution_1_100(random_engine);
}

std::vector<Asteroid> Mechanics::createAsteroids()
{
    int blockWidth{30}, blockHeight{10};
    float velocity{1.f};
    if(this->time <= this->clock.getElapsedTime()) {
        Asteroid asteroid(createRandom(), -blockWidth, blockWidth, blockHeight);
        asteroid.setVelocity(velocity);
        this->asteroids.push_back(asteroid);
        this->clock.restart();
    }
    return asteroids;
}

Mechanics::Mechanics(Ship &ship)
{
    this->ship = &ship;
    this->asteroids = createAsteroids();
    this->bullets = &ship.getBullets();
    this->clock = sf::Clock();
    clock.restart();
    this->time = sf::milliseconds(300);
}

template <class T>
void updateVector(std::vector<T> &models)
{
    auto iterator = remove_if (begin(models), end(models), [](Model &model) {return model.isDestroyed(); });
    models.erase(iterator, end(models));
}

void Mechanics::update()
{
    createAsteroids();
    updateVector(asteroids);
    updateVector(*bullets);
    Physics::getInstance().checkCollision(asteroids, *bullets);
    Physics::getInstance().checkCollision(asteroids, *ship);
}

std::vector<Asteroid> &Mechanics::getAsteroids()
{
    return asteroids;
}

std::vector<Bullet> &Mechanics::getBullets()
{
    return *bullets;
}