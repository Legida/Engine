#include "physicsworld.h"
PhysicsWorld::PhysicsWorld()
{
    _gravity = 64.f * 18;
    _physicsFrameTime = sf::milliseconds(1000/60);
}

void PhysicsWorld::addBoundingBox(BoundingBox *object)
{
    _physBodiesList.push_back(object);
}

void PhysicsWorld::removeBoundingBox(BoundingBox *object)
{
    _physBodiesList.remove(object);
}

void PhysicsWorld::update(sf::Time dt)
{
    _timeCounter += dt;
    while(_timeCounter >= _physicsFrameTime)
    {
        _timeCounter -= _physicsFrameTime;
        step(_physicsFrameTime);
    }
}

void PhysicsWorld::step(sf::Time dt)
{
    float time = dt.asSeconds();

    for(auto object : _physBodiesList)
    {
        auto obj_newSpeed = object->getSpeed();

        object->move(time);

        if(object->getGravitySubjection())
        {
            obj_newSpeed += sf::Vector2f(0, _gravity*time);
        }

        object->setSpeed(obj_newSpeed);

        for(auto object2 : _physBodiesList)
        {
            if (object == object2)
            {
                continue;
            }

            if (hasCollition(object, object2))
            {
                SATCollision(object, object2, time);
            }
        }

        object->update(time);
    }
}

void PhysicsWorld::setPhysicsFPS(int number)
{
    _physicsFrameTime = sf::milliseconds(1000/number);
}

void PhysicsWorld::setGravity(float gravity)
{
    _gravity = gravity;
}

bool PhysicsWorld::hasCollition(BoundingBox *object1, BoundingBox *object2)
{
    bool a1 = BoundingBox::lineIntersection   (object1->getPosition().x, object2->getPosition().x,
                                               object1->getSize().x, object2->getSize().x);

    bool a2 = BoundingBox::lineIntersection   (object1->getPosition().y, object2->getPosition().y,
                                               object1->getSize().y, object2->getSize().y);

    return a1 && a2;
}

bool PhysicsWorld::SATCollision(BoundingBox *object1, BoundingBox *object2, float dt)
{
    bool result = false;

    auto resultVec = object1->getBody()->collisionDetection(object2->getBody());

    if (resultVec == sf::Vector2f(0, 0))
    {
        return false;
    }

    object1->collideFunc(object2, dt, resultVec);
    object2->collideFunc(object1, dt, -resultVec);

    return true;
}
