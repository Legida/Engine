#include "physicsbody.h"
#include "aabbbody.h"
#include "circlebody.h"
#include "polygonbody.h"

PhysicsBody::type PhysicsBody::getType()
{
    return _type;
}

sf::Vector2f PhysicsBody::AABBCollision(PhysicsBody *object1, PhysicsBody *object2)
{
    auto o1 = static_cast<AABBBody*>(object1);
    auto o2 = static_cast<AABBBody*>(object2);

    sf::Vector2f orientation = {-1, -1};

    float xmin = o1->getAnchor().x;
    float ymin = o1->getAnchor().y;
    float xmax = o1->getAnchor().x + o1->getSize().x;
    float ymax = o1->getAnchor().y + o1->getSize().y;

    if (xmin > o2->getAnchor().x)
    {
        xmin = o2->getAnchor().x;
        orientation.x = 1;
    }

    if (ymin > o2->getAnchor().y)
    {
        ymin = o2->getAnchor().y;
        orientation.y = 1;
    }

    if (xmax < o2->getAnchor().x + o2->getSize().x)
    {
        xmax = o2->getAnchor().x + o2->getSize().x;
    }

    if (ymax < o2->getAnchor().y + o2->getSize().y)
    {
        ymax = o2->getAnchor().y + o2->getSize().y;
    }

    auto r1x = (xmax - xmin) - (o1->getSize().x + o2->getSize().x);
    auto r1y = (ymax - ymin) - (o1->getSize().y + o2->getSize().y);

    if(r1x > 0 || r1y > 0)
    {
        return sf::Vector2f(0, 0);
    }

    if(std::abs(r1x) < std::abs(r1y))
    {
        return sf::Vector2f(r1x * orientation.x, 0);
    }
    else
    {
        return sf::Vector2f(0, r1y * orientation.y);
    }
}

sf::Vector2f PhysicsBody::CircleAABBCollision(PhysicsBody *circle, PhysicsBody *AABB)
{
    return sf::Vector2f(0, 0);
}

sf::Vector2f PhysicsBody::CircleCollision(PhysicsBody *object1, PhysicsBody *object2)
{
    return sf::Vector2f(0, 0);
}

sf::Vector2f PhysicsBody::AABBPolyCollision(PhysicsBody *AABB, PhysicsBody *poly)
{
    return sf::Vector2f(0, 0);
}

sf::Vector2f PhysicsBody::CirclePolyCollision(PhysicsBody *circle, PhysicsBody *poly)
{
    return sf::Vector2f(0, 0);
}

sf::Vector2f PhysicsBody::PolyCollision(PhysicsBody *object1, PhysicsBody *object2)
{
    return sf::Vector2f(0, 0);
}

PhysicsBody::PhysicsBody()
{

}
