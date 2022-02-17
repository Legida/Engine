#ifndef CIRCLEBODY_H
#define CIRCLEBODY_H
#include "physicsbody.h"

class CircleBody : public PhysicsBody
{
public:
    CircleBody(float radius, sf::Vector2f _center);

    sf::Vector2f getCenter();
    float getRadius();
    void move(sf::Vector2f speed) override;
    void setPosition(sf::Vector2f pos);

    sf::Vector2f collisionDetection(PhysicsBody* object2) override;
protected:
    float _radius;
    sf::Vector2f _center;
};

#endif // CIRCLEBODY_H
