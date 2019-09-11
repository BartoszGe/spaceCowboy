#ifndef PHYSICS_H
#define PHYSICS_H

#include <SFML/Graphics.hpp>
#include <random>
#include "model.h"
#include "ship.h"


class Physics
{
    private:
        Physics() {}
        
    public:

        static int createRandom()
        {
            std::random_device random_device;
            std::mt19937 random_engine(random_device());
            std::uniform_int_distribution<int> distribution_1_100(50, 750);
            return distribution_1_100(random_engine);
        }

        static bool isIntersecting(Model &model1, Model &model2)
        {
            return 
            model1.getTopBound() <= model2.getBottomBound() &&
            model1.getBottomBound() >= model2.getTopBound() &&
            model1.getRightBound() >= model2.getLeftBound() &&
            model1.getLeftBound() <= model2.getRightBound();
        }

        static bool isCollision(Model &model1, Model &model2)
        {
            if (isIntersecting(model1, model2)) {
                return true;
            }
            return false;
        }

        static bool isOutOfBounds(Model &model)
        {
            return 
            model.getTopBound() <= -50 ||
            model.getBottomBound() >= 850;
        }

        template <class T>
        static void checkOutOfBounds(std::vector<T> &models)
        {
            for (T &model: models) {
                if (isOutOfBounds(model)) {
                    model.destroy();
                }
            }
        }

        template <class T, class K>
        static void checkCollision(std::vector<T> &models1, std::vector<K> &models2)
        {
            for (T &model1: models1) {
                for (K &model2: models2) {
                    if (isCollision(model1, model2)) {
                        model1.destroy();
                        model2.destroy();
                    }
                }   
            }
        }

        template <class T, class K>
        static void checkCollision(std::vector<T> &models, K model2)
        {
            for (T &model1: models) {
                if (isCollision(model1, model2)) {
                    model1.destroy();
                    model2.destroy();
                    exit (0);
                }
            }
        }
};

#endif