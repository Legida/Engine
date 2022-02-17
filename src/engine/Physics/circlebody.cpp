#include "circlebody.h"

CircleBody::CircleBody(float radius, sf::Vector2f _center) : PhysicsBody()
{
    _type = type::circle;
}

sf::Vector2f CircleBody::getCenter()
{
    return _center;
}

float CircleBody::getRadius()
{
    return _radius;
}

void CircleBody::move(sf::Vector2f speed)
{
    _center += speed;
}

void CircleBody::setPosition(sf::Vector2f pos)
{
    _center = pos;
}

sf::Vector2f CircleBody::collisionDetection(PhysicsBody *object2)
{
    switch (object2->getType()) {
    case type::AABB:
        return CircleAABBCollision(this, object2);
    case type::circle:
        return CircleCollision(this, object2);
    case type::polygon:
        return CirclePolyCollision(this, object2);
    }
    return sf::Vector2f(0, 0);
}
