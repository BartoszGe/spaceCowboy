#include "mechanics.h"

std::vector<Asteroid> createAsteroids()
{
    unsigned blockX{2}, blockY{4}, blockWidth{60}, blockHeight{20};
    std::vector<Asteroid> asteroids;
    for (int i = 0; i < blockY; i++) {
        for (int j = 0; j < blockX; j++) {
            asteroids.emplace_back((j+1) * (blockWidth + 10), (i+2) * (blockHeight + 5), blockWidth, blockHeight);
        }
    }
    return asteroids;
}

Mechanics::Mechanics(Ship &ship)
{
    this->ship = &ship;
    this->asteroids = createAsteroids();
    this->bullets = &ship.getBullets();
}

template <class T>
void updateVector(std::vector<T> &models)
{
    auto iterator = remove_if (begin(models), end(models), [](Model &model) {return model.isDestroyed(); });
    models.erase(iterator, end(models));
}

void Mechanics::update()
{
    updateVector(asteroids);
    updateVector(*bullets);

    for (Bullet &bullet: *bullets) {
        for (Asteroid &asteroid: asteroids) {
            if (Physics::getInstance().isCollision(bullet, asteroid)) {
                bullet.destroy();
                asteroid.destroy();
                break;
            }
        }   
    }
}

std::vector<Asteroid> &Mechanics::getAsteroids()
{
    return asteroids;
}

std::vector<Bullet> &Mechanics::getBullets()
{
    return *bullets;
}