#include "aabbbody.h"

AABBBody::AABBBody(sf::Vector2f anchor, sf::Vector2f size) : PhysicsBody(), _anchor(anchor), _size(size)
{
    _type = type::AABB;
}

void AABBBody::move(sf::Vector2f speed)
{
    _anchor += speed;
}

void AABBBody::setPosition(sf::Vector2f pos)
{
    _anchor = pos;
}

sf::Vector2f AABBBody::getAnchor()
{
    return _anchor;
}

sf::Vector2f AABBBody::getSize()
{
    return _size;
}

sf::Vector2f AABBBody::collisionDetection(PhysicsBody *object2)
{
    switch (object2->getType()) {
    case type::AABB:
        return AABBCollision(this, object2);
    case type::circle:
        return CircleAABBCollision(object2, this);
    case type::polygon:
        return AABBPolyCollision(this, object2);
    }
    return sf::Vector2f(0, 0);
}

