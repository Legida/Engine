#ifndef PHYSICSBODY_H
#define PHYSICSBODY_H
#include "SFML/Graphics.hpp"

class PhysicsBody
{
public:
    PhysicsBody();

    enum type
    {
        polygon,
        circle,
        AABB
    };

    type getType();
    virtual void move(sf::Vector2f speed) = 0;

    virtual sf::Vector2f collisionDetection(PhysicsBody* object2) = 0;

protected:
    type _type;

    sf::Vector2f AABBCollision(PhysicsBody* object1, PhysicsBody* object2);
    sf::Vector2f CircleAABBCollision(PhysicsBody* circle, PhysicsBody* AABB);
    sf::Vector2f CircleCollision(PhysicsBody* object1, PhysicsBody* object2);
    sf::Vector2f AABBPolyCollision(PhysicsBody* AABB, PhysicsBody* poly);
    sf::Vector2f CirclePolyCollision(PhysicsBody* circle, PhysicsBody* poly);
    sf::Vector2f PolyCollision(PhysicsBody* object1, PhysicsBody* object2);
};

#endif // PHYSICSBODY_H
