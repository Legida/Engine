#ifndef PHYSICSWORLD_H
#define PHYSICSWORLD_H
#include "SFML/Graphics.hpp"
#include "boundingbox.h"

class PhysicsWorld
{
public:
    PhysicsWorld();

    void addBoundingBox(BoundingBox* object);
    void removeBoundingBox(BoundingBox* object);

    void update(sf::Time dt);
    void step(sf::Time dt);

    void setPhysicsFPS(int number);
    void setGravity(float gravity);

protected:
    bool hasCollition(BoundingBox* object1, BoundingBox* object2);
    bool SATCollision(BoundingBox* object1, BoundingBox* object2, float dt);

    float _gravity;
    sf::Time _timeCounter;
    sf::Time _physicsFrameTime;
    std::list<BoundingBox*> _physBodiesList;
};

#endif // PHYSICSWORLD_H
